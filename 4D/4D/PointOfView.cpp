#include "stdafx.h"
#include "PointOfView.hpp"

PointOfView::PointOfView()
    : circle(5)
{
    //circle.setPosition(f.at(0)*100.f + mGlobalOffset.at(0), f.at(1)*100.f + mGlobalOffset.at(1));
    //Issue: What meaning has the f. ??? f means float!!!
    circle.setOrigin(5,5);
    circle.setPosition(mGlobalOffset.at(0), mGlobalOffset.at(1));
    circle.setFillColor(sf::Color::Blue);
}

PointOfView::~PointOfView()
{

}

void PointOfView::handleEvents()
{

}

void PointOfView::update(sf::Time &elapsed)
{

}

void PointOfView::render(sf::RenderWindow *pRenderWindow, fd::Matrix44f *view, fd::Vector4f *position)
{
    (*pRenderWindow).draw(circle);
}
