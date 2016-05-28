#include "Observer.hpp"


Observer::Observer()
{
    for(int i = 0; i < 4; i++)
    {
        mPosition.at(i) = 0.f;
    }

}

Observer::Observer(fd::Vector4f _position, fd::Matrix4f _view)
    : mPosition(_position), mView(_view)
{

}

Observer::~Observer()
{

}

Observer::rotationX1(float phi)
{
    fd::Matrix4f rotMatrix();
    rotMatrix.at(0,0) = cos(phi);
}
