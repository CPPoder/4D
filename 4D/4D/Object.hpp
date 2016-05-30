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
    virtual void render() = 0;

    fd::Vector4f transfromToObserversView(fd::Vector4f const &positionObserver, fd::Matrix44f const &viewObserver, fd::Vector4f const &point);

    fd::Vector2f parallelProjection(fd::Vector4f pointIn);


};

#endif // OBJECT_HPP
