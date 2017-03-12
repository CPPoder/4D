#ifndef OBSERVER_HPP
#define OBSERVER_HPP
#include "ourVectors.hpp"
#include "ourMatrices.hpp"

class Observer
{
private:
    fd::Vector4f mPosition;
    fd::Matrix44f mView; // Matrix, contains the map observer system --> standard system

public:

    int mMoveAD;
    int mMoveWS;
    int mMoveXY;
    int mMoveFB;
    int mMoveLR;

    Observer();
    ~Observer();

    void update(sf::Time &elapsed, float sensitivity);

    fd::Matrix44f* getMView();
    fd::Vector4f* getMPosition();

    void render();

    void rotationX1(float phi);
    void rotationX2(float phi);
    void rotationY(float phi);

};


#endif // OBSERVER_HPP
