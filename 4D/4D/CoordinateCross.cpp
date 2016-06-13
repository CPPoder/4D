#include "CoordinateCross.hpp"
#include "SFML/Graphics.hpp"
#include <vector>
#include "stdafx.h"

CoordinateCross::CoordinateCross()
    : mVertexArray(sf::Lines, 8), mPosition2D(100.f, 700.f)
{

}

CoordinateCross::~CoordinateCross()
{

}

void CoordinateCross::render(sf::RenderWindow *pRenderWindow, fd::Matrix44f *view, fd::Vector4f *position, float colorDeepness)
{

}

void CoordinateCross::fillVertexArray()
{
    //Set positions
    mVertexArray[0].position = mPosition2D;
    mVertexArray[2].position = mPosition2D;
    mVertexArray[4].position = mPosition2D;
    mVertexArray[6].position = mPosition2D;
    mVertexArray[1].position = mPosition2D + sf::Vector2f(50.f, 0);
    mVertexArray[3].position = mPosition2D + sf::Vector2f(0, -50.f);
    mVertexArray[5].position = mPosition2D + sf::Vector2f(30.f, -30.f);
    mVertexArray[7].position = mPosition2D + sf::Vector2f(-30.f, -30.f);

    //Set colors
    mVertexArray[0].color = projectionColor(fd::Vector4f(std::vector<4f>(0.f, 0.f, )))



}


//CoodinateCross::
