#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "element.hpp"
#include "ourVectors.hpp"
#include "ourMatrices.hpp"


class Object : public Element
{
private:
    fd::Vector4f mPosition;

public:
    Object();
    virtual ~Object();

    virtual void handleEvents() = 0;
    virtual void update(sf::Time &elapsed) = 0;
    virtual void render(sf::RenderWindow *pRenderWindow, fd::Matrix44f *view, fd::Vector4f *position, float colorDeepness) = 0;

    fd::Vector4f transformToObserversView(fd::Vector4f *positionObserver, fd::Matrix44f *viewObserver, fd::Vector4f point);

    fd::Vector2f parallelProjection(fd::Vector4f pointIn);

    unsigned int projectionColor1(float xIn, float colorDeepness);

    //Input: An edge, whose coordinates may be smaller than 0 in dim 3,4 --> they shall not be projected, as they are behind the observer
    //Output: Edge, which is the visible part of the input
    fd::Matrix42f correctEdge(fd::Vector4f vectorIn1, fd::Vector4f vectorIn2);



};

#endif // OBJECT_HPP
