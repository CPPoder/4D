#include "Point.hpp"

Point::Point(fd::Vector4f _position)
    : mPosition(_position)
{

}

Point::~Point()
{

}

void Point::handleEvents()
{

}

void Point::update(sf::Time& elapsed)
{

}

void Point::render(sf::RenderWindow *pRenderWindow, fd::Matrix44f *view, fd::Vector4f *position)
{

    if(mParallelProjection)
    {

    }
    else
    {
        fd::Vector4f pos = transformToObserversView(position, view, mPosition);
        float distanceToObserver = sqrt(pos*pos);
        std::cout << "distance to Observer: " << distanceToObserver << std::endl;
        sf::CircleShape circle(10/log(distanceToObserver + 1));
        circle.setPosition(spatialProjection(pos).at(0) + mGlobalOffset.at(0), spatialProjection(pos).at(1) + mGlobalOffset.at(1));
        (*pRenderWindow).draw(circle);
    }
}
