#ifndef OBSERVER_HPP
#define OBSERVER_HPP
#include "ourVectors.hpp"
#include "ourMatrices.hpp"

class Observer
{
private:
    fd::Vector4f mPosition;
    fd::Matrix44f mView; // Matrix, contains the map standard system --> observer system

public:

    Observer();
    ~Observer();

    void update();

    void rotationX1(float phi);
    void rotationX2(float phi);
    void rotationY(float phi);

};







#endif // OBSERVER_HPP
