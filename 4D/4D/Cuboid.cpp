#include "stdafx.h"
#include "SFML\Graphics.hpp"
#include <vector>
#include "ourVectors.hpp"
#include "Cuboid.hpp"

//Constructor
Cuboid::Cuboid(fd::Vector4f _position, fd::Vector4f _diagonal)
    : mPosition(_position), mDiagonal(_diagonal)
{
    fd::Vector4f vector4fTemp(0);
    for(int i = 0; i < 16; i++)
    {
        mCorners.push_back(vector4fTemp);
    }
    fillCorners();
    fillEdgeMap();


}

//Destructor
Cuboid::~Cuboid()
{

}

/*std::vector<sf::VertexArray> getEdges()
{

}
*/

void Cuboid::handleEvents()
{

}

void Cuboid::render(sf::RenderWindow *pRenderWindow, fd::Matrix44f *view, fd::Vector4f *position)
{
    //Part 1: Compute the coordinates of the corners in observers coordinates
    //The order is given by: start with the edge at the position vector, then add the diagonal componentwise wrt the schema 0000, 0001, 0010, ..., 1111
    std::vector <fd::Vector4f> mCornersViewed(0.f); //the corners coordinates from the observers point of view

    for(int i = 0; i < 16; i++)
    {
        mCornersViewed.push_back(transformToObserversView(position, view, mCorners.at(i)));
    }

    //Part 2: Construct the corners of the cube
    for(int i = 0; i < 16; i++)
    {
        fd::Vector4f pos = transformToObserversView(position, view, mCorners.at(i));
        if (isPointVisible(pos))
        {
            float dist = sqrt(pos*pos);

            float adoptedSize = 100.f/(dist);
            sf::CircleShape circle(adoptedSize);
            circle.setOrigin(adoptedSize, adoptedSize);
            circle.setPosition(pureColorProjection(pos).at(0)*zoom + mGlobalOffset.at(0), pureColorProjection(pos).at(1)*zoom + mGlobalOffset.at(1));
            circle.setFillColor(colorPureColor(pos, 0, 20));
            (*pRenderWindow).draw(circle);
        }
    }



    //Part 3: Construct VertexArray containing all the edges
    sf::VertexArray tEdges(sf::Lines, 64);
    int counter = 0; //Counts the edges written to tEdges
    fd::Vector4f point1; //Placeholder
    fd::Vector4f point2;

    for (int i = 0; i < 32; i++)
    {
        point1 = mCornersViewed.at(mEdgeMapIndex.at(counter)); //the two points which constitute an edge, mEdgeMapIndex maps the number 0 ... 63 to the
        point2 = mCornersViewed.at(mEdgeMapIndex.at(counter+1)); //index of the corresponding vertex, mCornersViewed returns the position
        fd::Matrix42f temp = correctEdge(point1, point2);

        for (int k = 0; k < 4; k++)
        {
            point1.at(k) = temp.at(k, 0);
            point2.at(k) = temp.at(k, 1);
        }

        tEdges[counter].position = sf::Vector2f(pureColorProjection(point1).at(0)*zoom + mGlobalOffset.at(0), pureColorProjection(point1).at(1)*zoom + mGlobalOffset.at(1));
        tEdges[counter].color = colorPureColor(point1, 0, 20);
        counter += 1;
        tEdges[counter].position = sf::Vector2f(pureColorProjection(point2).at(0)*zoom + mGlobalOffset.at(0), pureColorProjection(point2).at(1)*zoom + mGlobalOffset.at(1));
        tEdges[counter].color = colorPureColor(point2, 0, 20);
        counter += 1;
    }
    (*pRenderWindow).draw(tEdges);
}








    /*switch(mProjectionManner)
    {
    case 0: //Pure color
        {

        }
    case 1: //Spatial projection
        {
    //Part 1: Compute the coordinates of the corners in observers coordinates
    //The order is given by: start with the edge at the position vector, then add the diagonal componentwise wrt the schema 0000, 0001, 0010, ..., 1111
            std::vector <fd::Vector2f> mCornersProjected;
            std::vector <sf::Color> mCornersColors;
            for(int i = 0; i < 16; i++)
            {
                mCornersProjected.push_back(fd::Vector2f(0.f));
                mCornersColors.push_back(sf::Color(0, 0, 0, 255));
            }
            for(int i = 0; i < 16; i++)
            {
                mCornersProjected.at(i) = spatialProjection(transformToObserversView(position, view, mCorners.at(i))) + mGlobalOffset;
            }

            for(int i = 0; i < 16; i++)
            {
                mCornersColors.at(i) = projectionColor((transformToObserversView(position, view, mCorners.at(i))), mColorDeepness);
            }



    //This function has to be optimized!!!!
    //Part 2: Construct VertexArray containing all the edges
            sf::VertexArray tEdges(sf::Lines, 64);
            int counter = 0;
            int index; // Number of the corresponding corner, between 0 - 15
            //std::cout << "mView: " << view->at(0,0) << "," << view->at(0,1) << "," << view->at(1,1) << "," << view->at(2,1) << "," << view->at(3,1) << std::endl;
            //Write the edges in x1 direction
            for(int a2 = 0; a2 < 2; a2 ++)
            {
                for(int a3 = 0; a3 < 2; a3 ++)
                {
                    for(int a4 = 0; a4 < 2; a4 ++)
                    {
                        index = 4*a2 + 2*a3 + a4;
                        tEdges[counter].position = sf::Vector2f(mCornersProjected[index].at(0), mCornersProjected[index].at(1));
                        tEdges[counter].color = mCornersColors[index];
                        counter += 1;
                        index += 8;
                        tEdges[counter].position = sf::Vector2f(mCornersProjected[index].at(0), mCornersProjected[index].at(1));
                        tEdges[counter].color = mCornersColors[index];
                        counter += 1;
                    }
                }
            }

            //Write the edges in x2 direction
            for(int a1 = 0; a1 < 2; a1 ++)
            {
                for(int a3 = 0; a3 < 2; a3 ++)
                {
                    for(int a4 = 0; a4 < 2; a4 ++)
                    {
                        index = 8*a1 + 2*a3 + a4;
                        tEdges[counter].position = sf::Vector2f(mCornersProjected[index].at(0), mCornersProjected[index].at(1));
                        tEdges[counter].color = mCornersColors[index];
                        counter += 1;
                        index += 4;
                        tEdges[counter].position = sf::Vector2f(mCornersProjected[index].at(0), mCornersProjected[index].at(1));
                        tEdges[counter].color = mCornersColors[index];
                        counter += 1;
                    }
                }
            }

            //Write the edges in x3 direction
            for(int a1 = 0; a1 < 2; a1 ++)
            {
                for(int a2 = 0; a2 < 2; a2 ++)
                {
                    for(int a4 = 0; a4 < 2; a4 ++)
                    {
                        index = 8*a1 + 4*a2 + a4;
                        tEdges[counter].position = sf::Vector2f(mCornersProjected[index].at(0), mCornersProjected[index].at(1));
                        tEdges[counter].color = mCornersColors[index];
                        counter += 1;
                        index += 2;
                        tEdges[counter].position = sf::Vector2f(mCornersProjected[index].at(0), mCornersProjected[index].at(1));
                        tEdges[counter].color = mCornersColors[index];
                        counter += 1;
                    }
                }
            }

            //Write the edges in x4 direction
            for(int a1 = 0; a1 < 2; a1 ++)
            {
                for(int a2 = 0; a2 < 2; a2 ++)
                {
                    for(int a3 = 0; a3 < 2; a3 ++)
                    {
                        index = 8*a1 + 4*a2 + 2*a3;
                        tEdges[counter].position = sf::Vector2f(mCornersProjected[index].at(0), mCornersProjected[index].at(1));
                        tEdges[counter].color = mCornersColors[index];
                        counter += 1;
                        index += 1;
                        tEdges[counter].position = sf::Vector2f(mCornersProjected[index].at(0), mCornersProjected[index].at(1));
                        tEdges[counter].color = mCornersColors[index];
                        counter += 1;
                    }
                }
            }
            (*pRenderWindow).draw(tEdges);


        }
    case 2: // parallel Projection
        {
            //Part 1: Compute the coordinates of the corners in observers coordinates
            //The order is given by: start with the edge at the position vector, then add the diagonal componentwise wrt the schema 0000, 0001, 0010, ..., 1111
            std::vector <fd::Vector2f> mCornersProjected;
            std::vector <sf::Color> mCornersColors;
            for(int i = 0; i < 16; i++)
            {
                mCornersProjected.push_back(fd::Vector2f(0.f));
                mCornersColors.push_back(sf::Color(0, 0, 0, 255));
            }
            for(int i = 0; i < 16; i++)
            {
                mCornersProjected.at(i) = parallelProjection(transformToObserversView(position, view, mCorners.at(i))) + mGlobalOffset;

            }
            for(int i = 0; i < 16; i++)
            {
                mCornersColors.at(i) = projectionColor((transformToObserversView(position, view, mCorners.at(i))), mColorDeepness);
            }

            //This function has to be optimized!!!!
            //Part 2: Construct VertexArray containing all the edges
            sf::VertexArray tEdges(sf::Lines, 64);
            int counter = 0;
            int index; // Number of the corresponding corner, between 0 - 15
            //std::cout << "mView: " << view->at(0,0) << "," << view->at(0,1) << "," << view->at(1,1) << "," << view->at(2,1) << "," << view->at(3,1) << std::endl;
            //Write the edges in x1 direction
            for(int a2 = 0; a2 < 2; a2 ++)
            {
                for(int a3 = 0; a3 < 2; a3 ++)
                {
                    for(int a4 = 0; a4 < 2; a4 ++)
                    {
                        index = 4*a2 + 2*a3 + a4;
                        tEdges[counter].position = sf::Vector2f(mCornersProjected[index].at(0), mCornersProjected[index].at(1));
                        tEdges[counter].color = mCornersColors[index];
                        counter += 1;
                        index += 8;
                        tEdges[counter].position = sf::Vector2f(mCornersProjected[index].at(0), mCornersProjected[index].at(1));
                        tEdges[counter].color = mCornersColors[index];
                        counter += 1;
                    }
                }
            }

            //Write the edges in x2 direction
            for(int a1 = 0; a1 < 2; a1 ++)
            {
                for(int a3 = 0; a3 < 2; a3 ++)
                {
                    for(int a4 = 0; a4 < 2; a4 ++)
                    {
                        index = 8*a1 + 2*a3 + a4;
                        tEdges[counter].position = sf::Vector2f(mCornersProjected[index].at(0), mCornersProjected[index].at(1));
                        tEdges[counter].color = mCornersColors[index];
                        counter += 1;
                        index += 4;
                        tEdges[counter].position = sf::Vector2f(mCornersProjected[index].at(0), mCornersProjected[index].at(1));
                        tEdges[counter].color = mCornersColors[index];
                        counter += 1;
                    }
                }
            }

            //Write the edges in x3 direction
            for(int a1 = 0; a1 < 2; a1 ++)
            {
                for(int a2 = 0; a2 < 2; a2 ++)
                {
                    for(int a4 = 0; a4 < 2; a4 ++)
                    {
                        index = 8*a1 + 4*a2 + a4;
                        tEdges[counter].position = sf::Vector2f(mCornersProjected[index].at(0), mCornersProjected[index].at(1));
                        tEdges[counter].color = mCornersColors[index];
                        counter += 1;
                        index += 2;
                        tEdges[counter].position = sf::Vector2f(mCornersProjected[index].at(0), mCornersProjected[index].at(1));
                        tEdges[counter].color = mCornersColors[index];
                        counter += 1;
                    }
                }
            }

            //Write the edges in x4 direction
            for(int a1 = 0; a1 < 2; a1 ++)
            {
                for(int a2 = 0; a2 < 2; a2 ++)
                {
                    for(int a3 = 0; a3 < 2; a3 ++)
                    {
                        index = 8*a1 + 4*a2 + 2*a3;
                        tEdges[counter].position = sf::Vector2f(mCornersProjected[index].at(0), mCornersProjected[index].at(1));
                        tEdges[counter].color = mCornersColors[index];
                        counter += 1;
                        index += 1;
                        tEdges[counter].position = sf::Vector2f(mCornersProjected[index].at(0), mCornersProjected[index].at(1));
                        tEdges[counter].color = mCornersColors[index];
                        counter += 1;
                    }
                }
            }
            (*pRenderWindow).draw(tEdges);
        }
    }

*/



void Cuboid::update(sf::Time &elapsed)
{

}

void Cuboid::fillCorners()
{
    fd::Vector4f diagonal1(0.f); //Vectors which contain only the one dim components of mDiagonal
    fd::Vector4f diagonal2(0.f);
    fd::Vector4f diagonal3(0.f);
    fd::Vector4f diagonal4(0.f);

    diagonal1.at(0) = mDiagonal.at(0); //Fill with the corresponding component
    diagonal2.at(1) = mDiagonal.at(1);
    diagonal3.at(2) = mDiagonal.at(2);
    diagonal4.at(3) = mDiagonal.at(3);

    fd::Vector4f temp;
    int index;
    for(int a1 = 0; a1 < 2; a1 ++)
    {
        for(int a2 = 0; a2 < 2; a2 ++)
        {
            for(int a3 = 0; a3 < 2; a3 ++)
            {
                for(int a4 = 0; a4 < 2; a4 ++)
                {
                    temp = mPosition + float(a1)*diagonal1 + float(a2)*diagonal2 + float(a3)*diagonal3 + float(a4)*diagonal4;
                    index = a4 + 2*a3 + 4*a2 + 8*a1; //Index in the array (0 to 15)
                    //append the corresponding point
                    mCorners.at(index) = temp;
                }
            }
        }
    }
}


void Cuboid::fillEdgeMap()
{
    int counter = 0; //Counts the entries of the EdgeMap
    fd::Vector4i vectorTemp; // A container for the dual description of the vertices filled in every run new
    //Write the edges in x1 direction
    for(int a2 = 0; a2 < 2; a2 ++)
    {
        for(int a3 = 0; a3 < 2; a3 ++)
        {
            for(int a4 = 0; a4 < 2; a4 ++)
            {
                vectorTemp.at(0) = 0;
                vectorTemp.at(1) = a2;
                vectorTemp.at(2) = a3;
                vectorTemp.at(3) = a4;
                mEdgeMap.push_back(vectorTemp);
                mEdgeMapIndex.push_back(a4 + 2*a3 + 4*a2 + 8*0);
                counter += 1;

                vectorTemp.at(0) = 1; //Only this 'coordinate' changes
                mEdgeMap.push_back(vectorTemp);
                mEdgeMapIndex.push_back(a4 + 2*a3 + 4*a2 + 8*1);
                counter += 1;
            }
        }
    }

    //Write the edges in x2 direction
    for(int a1 = 0; a1 < 2; a1 ++)
    {
        for(int a3 = 0; a3 < 2; a3 ++)
        {
            for(int a4 = 0; a4 < 2; a4 ++)
            {
                vectorTemp.at(0) = a1;
                vectorTemp.at(1) = 0;
                vectorTemp.at(2) = a3;
                vectorTemp.at(3) = a4;
                mEdgeMap.push_back(vectorTemp);
                mEdgeMapIndex.push_back(a4 + 2*a3 + 4*0 + 8*a1);
                counter += 1;

                vectorTemp.at(1) = 1; //Only this 'coordinate' changes
                mEdgeMap.push_back(vectorTemp);
                mEdgeMapIndex.push_back(a4 + 2*a3 + 4*1 + 8*a1);
                counter += 1;
            }
        }
    }

    //Write the edges in x3 direction
    for(int a1 = 0; a1 < 2; a1 ++)
    {
        for(int a2 = 0; a2 < 2; a2 ++)
        {
            for(int a4 = 0; a4 < 2; a4 ++)
            {
                vectorTemp.at(0) = a1;
                vectorTemp.at(1) = a2;
                vectorTemp.at(2) = 0;
                vectorTemp.at(3) = a4;
                mEdgeMap.push_back(vectorTemp);
                mEdgeMapIndex.push_back(a4 + 2*0 + 4*a2 + 8*a1);
                counter += 1;

                vectorTemp.at(2) = 1; //Only this 'coordinate' changes
                mEdgeMap.push_back(vectorTemp);
                mEdgeMapIndex.push_back(a4 + 2*1 + 4*a2 + 8*a1);
                counter += 1;
            }
        }
    }

    //Write the edges in x4 direction
    for(int a1 = 0; a1 < 2; a1 ++)
    {
        for(int a2 = 0; a2 < 2; a2 ++)
        {
            for(int a3 = 0; a3 < 2; a3 ++)
            {
                vectorTemp.at(0) = a1;
                vectorTemp.at(1) = a2;
                vectorTemp.at(2) = a3;
                vectorTemp.at(3) = 0;
                mEdgeMap.push_back(vectorTemp);
                mEdgeMapIndex.push_back(0 + 2*a3 + 4*a2 + 8*a1);
                counter += 1;

                vectorTemp.at(3) = 1; //Only this 'coordinate' changes
                mEdgeMap.push_back(vectorTemp);
                mEdgeMapIndex.push_back(1 + 2*a3 + 4*a2 + 8*a1);
                counter += 1;
            }
        }
    }
}

fd::Vector4f Cuboid::getPosition()
{
    return(Cuboid::mPosition);
}
