#include "stdafx.h"
#include "Point.hpp"

Point::Point(fd::Vector4f _position)
    : mPosition(_position), mSize(30.f)
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
    fd::Vector4f pos = transformToObserversView(position, view, mPosition);
    std::cout << pos.at(0) << " "  << pos.at(1) << " "  << pos.at(2) << " "  << pos.at(3) << std::endl;

    switch(mProjectionManner)
    {
    case 0: //pureColor
        {
            if (mRestrictVisibility && isPointVisible(pos))
            {
                float dist = sqrt(pos*pos);
                float dist3D = sqrt(pos.at(0)*pos.at(0) + pos.at(1)*pos.at(1) + pos.at(2)*pos.at(2));

                float adoptedSize = mSize/(dist - z0 + 1);
                sf::CircleShape circle(adoptedSize);
                circle.setOrigin(adoptedSize, adoptedSize);
                circle.setPosition(pureColorProjection(pos).at(0)*zoom + mGlobalOffset.at(0), pureColorProjection(pos).at(1)*zoom + mGlobalOffset.at(1));
                circle.setFillColor(colorPureColor(pos));
                (*pRenderWindow).draw(circle);

            }
            break;
        }
    case 1: //spatial
        {

            float distanceToObserver = sqrt(pos*pos);
            //std::cout << "distance to Observer: " << distanceToObserver << std::endl;
            sf::CircleShape circle(10/log(distanceToObserver + 1));
            circle.setPosition(spatialProjection(pos).at(0) + mGlobalOffset.at(0), spatialProjection(pos).at(1) + mGlobalOffset.at(1));
            (*pRenderWindow).draw(circle);
        }
    }
}
