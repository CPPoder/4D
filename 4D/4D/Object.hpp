#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "element.hpp"
#include "ourVectors.hpp"


class Object : public Element
{
private:
    fd::Vector4f mPosition;

public:
    Object();
    virtual ~Object();

    virtual void handleEvents() = 0;
    virtual void update() = 0;
    virtual void render() = 0;


};

#endif // OBJECT_HPP
