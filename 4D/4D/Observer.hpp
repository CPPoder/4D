#ifndef OBSERVER_HPP
#define OBSERVER_HPP
#include "ourVectors.hpp"

class Observer
{
private:
    fd::Vector4f mPosition;
    fd::Vector4f mView; //describes the direction the observer looks to

public:

    Observer();
    Observer(fd::Vector4f _position, fd::Vector4f _view);
    ~Observer();

    void update();

};







#endif // OBSERVER_HPP
