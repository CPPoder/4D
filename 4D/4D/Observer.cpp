#include "Observer.hpp"


Observer::Observer()
{
    for(int i = 0; i < 4; i++)
    {
        mPosition.at(i) = 0.f;
    }

    mView.at(0) = 1.f;

    for(int i = 1; i < 4; i++)
    {
        mView.at(i) = 0.f;
    }
}

Observer::Observer(fd::Vector4f _position, fd::Vector4f _view)
    : mPosition(_position), mView(_view)
{

}
