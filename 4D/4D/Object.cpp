#include "Object.hpp"
#include "ourMatrices.hpp"
#include "ourVectors.hpp"

Object::Object()
{

}

Object::~Object()
{

}

//Gets the observers position and mView matrix and calculates the coordinates of its own position in terms of the observers coordinates
fd::Vector4f Object::transfromToObserversView(fd::Vector4f const &positionObserver, fd::Matrix44f const &viewObserver, fd::Vector4f const &point)
{
    fd::Vector4f result;
    result = viewObserver*(point - positionObserver);
    return(result);
}


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
