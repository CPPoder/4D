#include "SFML\Graphics.hpp"
#include <vector>
#include "ourVectors.hpp"
#include "Cuboid.hpp"

//Constructor
Cuboid::Cuboid(fd::Vector4f _position, fd::Vector4f _diagonal)
    : mPosition(_position), mDiagonal(_diagonal)
{
    fillCorners();
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
    fd::Vector2f mCornersProjected [16];
    for(int i = 0; i < 16; i++)
    {
        mCornersProjected[i] = parallelProjection(transfromToObserversView(position, view, mCorners[i]));
    }

    //This function has to be optimized!!!!
    //Part 2: Construct VertexArray containing all the edges
    sf::VertexArray tEdges(sf::Lines, 64);
    int counter = 0;
    int index;
    std::cout << "mView: " << view->at(0,0) << view->at(0,1) << std::endl;
    //Write the edges in x1 direction
    for(int a2 = 0; a2 < 2; a2 ++)
    {
        for(int a3 = 0; a3 < 2; a3 ++)
        {
            for(int a4 = 0; a4 < 2; a4 ++)
            {
                index = 4*a2 + 2*a3 + a4;
                tEdges[counter].position = sf::Vector2f(mCornersProjected[index].at(0), mCornersProjected[index].at(0));
                counter += 1;
                index += 8;
                tEdges[counter].position = sf::Vector2f(mCornersProjected[index].at(0), mCornersProjected[index].at(0));
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
                tEdges[counter].position = sf::Vector2f(mCornersProjected[index].at(0), mCornersProjected[index].at(0));
                counter += 1;
                index += 4;
                tEdges[counter].position = sf::Vector2f(mCornersProjected[index].at(0), mCornersProjected[index].at(0));
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
                tEdges[counter].position = sf::Vector2f(mCornersProjected[index].at(0), mCornersProjected[index].at(0));
                counter += 1;
                index += 2;
                tEdges[counter].position = sf::Vector2f(mCornersProjected[index].at(0), mCornersProjected[index].at(0));
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
                tEdges[counter].position = sf::Vector2f(mCornersProjected[index].at(0), mCornersProjected[index].at(0));
                counter += 1;
                index += 1;
                tEdges[counter].position = sf::Vector2f(mCornersProjected[index].at(0), mCornersProjected[index].at(0));
                counter += 1;
            }
        }
    }
    std::cout << "Number of edges written: " << counter << std::endl;
    (*pRenderWindow).draw(tEdges);

}

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
                    mCorners[index] = temp;
                }
            }
        }
    }
}

fd::Vector4f Cuboid::getPosition()
{
    return(Cuboid::mPosition);
}

