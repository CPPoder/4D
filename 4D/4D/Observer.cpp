#include "Observer.hpp"
float const pi = 3.141592653f;


Observer::Observer()
    : mPosition(0.0f), mView(0.0f)
{
    //Set diagonal elements to 1 --> unity matrix
    for(int i = 0; i < 4; i++)
    {
        mView.at(i,i) = 1.0f;
    }
    //Multiply by rotation to match the (x1, x2, y, v) system in stead of the (x1, x2, x3, x4)
    rotationY(pi/4);
    std::cout << mView.at(2,2) << " " <<  mView.at(2,3) << " " << mView.at(3,2) << " " << mView.at(3,3) << std::endl;
}

Observer::~Observer()
{

}
//Rotation of v in towards x1-axis (leaves x2, y invariant)
void Observer::rotationX1(float phi)
{
    fd::Matrix44f rotMatrix (0.0f);
    rotMatrix.at(0,0) = cos(phi);
    rotMatrix.at(0,3) = sin(phi);
    rotMatrix.at(1,1) = 1.f;
    rotMatrix.at(2,2) = 1.f;
    rotMatrix.at(3,0) = -sin(phi);
    rotMatrix.at(3,3) = cos(phi);

    mView = mView*rotMatrix;
}

//Rotation of v in towards x2-axis (leaves x1, y invariant)
void Observer::rotationX2(float phi)
{
    fd::Matrix44f rotMatrix (0.0f);
    rotMatrix.at(0,0) = 1.f;
    rotMatrix.at(1,1) = cos(phi);
    rotMatrix.at(1,3) = sin(phi);
    rotMatrix.at(2,2) = 1.f;
    rotMatrix.at(3,1) = -sin(phi);
    rotMatrix.at(3,3) = cos(phi);

    mView = mView*rotMatrix;
}

//Rotation of v in towards x2-axis (leaves x1, y invariant)
void Observer::rotationY(float phi)
{
    fd::Matrix44f rotMatrix (0.0f);
    rotMatrix.at(0,0) = 1.f;
    rotMatrix.at(1,1) = 1.f;
    rotMatrix.at(2,2) = cos(phi);
    rotMatrix.at(2,3) = sin(phi);
    rotMatrix.at(3,2) = -sin(phi);
    rotMatrix.at(3,3) = cos(phi);

    mView = mView*rotMatrix;
}
