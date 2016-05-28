#ifndef OBSERVER_HPP
#define OBSERVER_HPP
#include "ourVectors.hpp"
#include "our4DMatrices.hpp"

class Observer
{
private:
    fd::Vector4f mPosition;
    fd::Matrix4f mView; // Matrix, contains the map standard system --> observer system

public:

    Observer();
    Observer(fd::Vector4f _position, fd::Matrix4f _view);
    ~Observer();

    void update();

    void rotationX1(float phi);

};







#endif // OBSERVER_HPP
