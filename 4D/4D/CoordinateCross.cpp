#include "stdafx.h"
#include "CoordinateCross.hpp"
#include "SFML/Graphics.hpp"
#include <vector>

CoordinateCross::CoordinateCross()
    : mVertexArray(sf::Lines, 8), mPosition2D(100.f, 300.f)
{
    fillVertexArray(mColorDeepness);
}

CoordinateCross::~CoordinateCross()
{

}

void CoordinateCross::update(sf::Time &elapsed)
{

}

void CoordinateCross::handleEvents()
{

}

void CoordinateCross::render(sf::RenderWindow *pRenderWindow, fd::Matrix44f *view, fd::Vector4f *position)
{
    (*pRenderWindow).draw(mVertexArray);
}

void CoordinateCross::fillVertexArray(float colorDeepness)
{
    //Set positions
    mVertexArray[0].position = mPosition2D - sf::Vector2f(50.f, 0);
    mVertexArray[2].position = mPosition2D - sf::Vector2f(0, -50.f);
    mVertexArray[4].position = mPosition2D - sf::Vector2f(30.f, -30.f);
    mVertexArray[6].position = mPosition2D - sf::Vector2f(-30.f, -30.f);
    mVertexArray[1].position = mPosition2D + sf::Vector2f(50.f, 0);
    mVertexArray[3].position = mPosition2D + sf::Vector2f(0, -50.f);
    mVertexArray[5].position = mPosition2D + sf::Vector2f(30.f, -30.f);
    mVertexArray[7].position = mPosition2D + sf::Vector2f(-30.f, -30.f);

    //Set colors
    mVertexArray[0].color = projectionColor(fd::Vector4f(std::vector<float>({0.f, 0.f,  0.f,  0.f})), mColorDeepness);
    mVertexArray[2].color = projectionColor(fd::Vector4f(std::vector<float>({0.f, 0.f,  0.f,  0.f})), mColorDeepness);
    mVertexArray[4].color = projectionColor(fd::Vector4f(std::vector<float>({0.f, 0.f,  -10.f,  0.f})), mColorDeepness);
    mVertexArray[6].color = projectionColor(fd::Vector4f(std::vector<float>({0.f, 0.f,  0.f,  -10.f})), mColorDeepness);
    mVertexArray[1].color = projectionColor(fd::Vector4f(std::vector<float>({0.f, 0.f,  0.f,  0.f})), mColorDeepness);
    mVertexArray[3].color = projectionColor(fd::Vector4f(std::vector<float>({0.f, 0.f,  0.f,  0.f})), mColorDeepness);
    mVertexArray[5].color = projectionColor(fd::Vector4f(std::vector<float>({0.f, 0.f,  10.f,  0.f})), mColorDeepness);
    mVertexArray[7].color = projectionColor(fd::Vector4f(std::vector<float>({0.f, 0.f,  0.f,  10.f})), mColorDeepness);
}


//CoodinateCross::
