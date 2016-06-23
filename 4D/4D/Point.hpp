#ifndef POINT_HPP
#define POINT_HPP

#include "Object.hpp"

class Point : public Object
{
private:
    fd::Vector4f mPosition;

public:
    Point(fd::Vector4f _position);
    ~Point() override;

    void handleEvents() override;
    void update(sf::Time& elapsed) override;
    void render(sf::RenderWindow *pRenderWindow, fd::Matrix44f *view, fd::Vector4f *position) override;

};
#endif // POINT_HPP
