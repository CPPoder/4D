#include "stdafx.h"
#include "Object.hpp"
#include "ourMatrices.hpp"
#include "ourVectors.hpp"
#include <algorithm>
#include <cmath>

Object::Object()
    : mGlobalOffset({720.0f, 450.0f}), mColorDeepness(1.f), alpha({0.5f, 0.5f}), f1({500.f, -300.f}), f2({-500.f, -300.f}), f({0., -1.f}), z0(1.f), mProjectionManner(0), mRestrictVisibility(true)
{

}

Object::~Object()
{

}

//Gets the observers position and mView matrix and calculates the coordinates of the points position in terms of the observers coordinates
fd::Vector4f Object::transformToObserversView(fd::Vector4f *positionObserver, fd::Matrix44f *viewObserver, fd::Vector4f point)
{
    fd::Vector4f result;
    result = *viewObserver*(point - *positionObserver);
    return(result);
}

//Projects a point onto its position on the screen
fd::Vector2f Object::parallelProjection(fd::Vector4f pointIn)
{
    fd::Matrix24f projectionMatrix(0.f);
    projectionMatrix.at(0,0) = 1.f;
    projectionMatrix.at(0,2) = 0.5f;
    projectionMatrix.at(0,3) = -0.5;
    projectionMatrix.at(1,1) = 1.f;
    projectionMatrix.at(1,2) = -0.5f;
    projectionMatrix.at(1,3) = -0.5f;

    fd::Vector2f result;
    result = projectionMatrix*pointIn;
    return(result);

}


//Projects a point onto its position in a spatial manner - in compairison to the parallelProjection method
fd::Vector2f Object::spatialProjection(fd::Vector4f pointIn)
{
    fd::Vector2f result;
    fd::Vector2f x1x2 ({pointIn.at(0), pointIn.at(1)});
    //exponential decay:
    //result = fd::componentwiseMultiplication(x1x2 + (f1 - x1x2)*float((1 - pow(0.5, pointIn.at(2)/l0))) + (f2 - x1x2)*float((1 - pow(0.5, pointIn.at(3)/l0))), alpha);
    //linear decay:
    //wrong!
    result = fd::componentwiseMultiplication(f1 + f2 - (f1 - x1x2)*(1/(pointIn.at(2) - z0 +1)) - (f2 - x1x2)*(1/pointIn.at(3)),alpha);
    return(result);
}

//Does the simple 3D to 2D projection, fourth dim will be encoded in color
fd::Vector2f Object::pureColorProjection(fd::Vector4f pointIn)
{
    fd::Vector2f result;
    fd::Vector2f x1x2 ({pointIn.at(0), pointIn.at(1)});

    result = f - (f - x1x2)/(pointIn.at(2) - z0 + 1);
    return(result);
}

//encodes the fourth dim in color when using the pureColor projection
//Idea: walk through the rainbow from red to yellow to green to blue (red for near distance, blue for large)
//The color encodes distances between 1 and 20
sf::Color Object::colorPureColor(fd::Vector4f xIn)
{
    sf::Color result(0,0,0,255);
    float dist = xIn.at(3);
    if (dist < 5)
    {
        result.r = 255;
        result.g = int(floor((dist-0.f)*51));
        result.b = 0;
    }
    else
    {
        if(dist < 10)
        {
            result.r = int(floor((10.f - dist)*51));
            result.g = 255;
            result.b = 0;
        }
        else
        {
            if(dist < 15)
            {
                result.r = 0;
                result.g = 255;
                result.b = int(floor((dist - 10.f)*51));
            }
            else
            {
                if(dist < 20)
                {
                    result.r = 0;
                    result.g = int(floor((20.f - dist)*51));
                    result.b = 255;
                }
                else
                {
                    result.r = 0;
                    result.g = 0;
                    result.b = 255;
                }
            }
        }
    }
    return(result);
}



//Returns unsigned int in range 0 - 256 (adopted to rgb colors)
//Points with high input value get a high output
sf::Color Object::projectionColor(fd::Vector4f xIn, float colorDeepness)
{
    sf::Color result(0, 0, 50, 255);
    result.r = colorScaling(xIn.at(2), colorDeepness);
    result.g = colorScaling(xIn.at(3), colorDeepness);
    return(result);
}

int Object::colorScaling(float xIn, float colorDeepness)
{
    int result = int(floor(128*(1-exp(-colorDeepness*std::abs(xIn)))));
    if (xIn < 0)
    {
        result = result*(-1);
    }
    return(result + 128);
}

//Input: An edge, whose coordinates may be smaller than 0 in dim 3,4 --> they shall not be projected, as they are behind the observer
//Output: Edge, which is the visible part of the input (*visible in some sense, explained in the docs)
fd::Matrix42f Object::correctEdge(fd::Vector4f vectorIn1, fd::Vector4f vectorIn2)
{
    fd::Matrix42f result(0.0f);
    result.at(0,0) = vectorIn1.at(0);
    result.at(1,0) = vectorIn1.at(1);
    result.at(0,1) = vectorIn2.at(0);
    result.at(1,1) = vectorIn2.at(1);

    float x1 = vectorIn1.at(2);
    float x2 = vectorIn1.at(3);
    float y1 = vectorIn2.at(2);
    float y2 = vectorIn2.at(3);

    if (x1 >= 0 && x2 >= 0 && y1 >= 0 && y2 >= 0) //Case A
    {
        result.at(2,0) = vectorIn1.at(2);
        result.at(3,0) = vectorIn1.at(3);
        result.at(2,1) = vectorIn2.at(2);
        result.at(3,1) = vectorIn2.at(3);
    }
    else
    {
        float t1 = x1/(x1 - y1);
        float t2 = x2/(x2 - y2);
        if (t1 < 0 || t1 > 1)
        {
            t1 = 2.f;
        }
        if (t2 < 0 || t2 > 1)
        {
            t2 = 2.f;
        }
        if (y1 >= 0 && y2 >= 0) //Case B, part 1
        {
            float t = std::min(t1, t2);
            result.at(2,1) = vectorIn1.at(2);
            result.at(3,1) = vectorIn1.at(3);
            result.at(2,0) = (1 - t)*x1 + t*y1;
            result.at(3,0) = (1 - t)*x2 + t*y2;
        }
        else
        {
            if (x1 >= 0 && x2 >= 0) //Case B, part 2
            {
                float t = std::min(t1, t2);
                result.at(2,0) = vectorIn1.at(2);
                result.at(3,0) = vectorIn1.at(3);
                result.at(2,1) = (1 - t)*x1 + t*y1;
                result.at(3,1) = (1 - t)*x2 + t*y2;
            }
            else
            {
                //Case c, as both are invisible
                if ((x1 < 0 && x2 >= 0 && y1 >= 0 && y2 < 0) ||(x1 >= 0 && x2 < 0 && y1 < 0 && y2 >= 0))
                {
                    if ((x1*(t1 - t2)) > 0) //Part is visible
                    {

                        result.at(2, 0) = (1 - t1)*x1 + t1*y1;
                        result.at(3, 0) = (1 - t1)*x2 + t1*y2;
                        result.at(2, 1) = (1 - t2)*x1 + t2*y1;
                        result.at(3, 1) = (1 - t2)*x2 + t2*y2;
                    }

                }
            }
        }
    }
    return(result);
}

 bool Object::isPointVisible(fd::Vector4f point)
 {
     float dist = point*point;
     if ((dist > z0*z0) && (point.at(2) >= 0) && (point.at(3) >= 0))
     {
         return(true);
     }
     else
     {
         return(false);
     }
 }

