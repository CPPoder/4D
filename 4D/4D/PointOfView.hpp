#ifndef POINT_OF_VIEW
#define POINT_Of_VIEW

#include "Object.hpp"
#include "ourVectors.hpp"

class PointOfView : public Object
{
private:
    sf::CircleShape circle;


public:
    PointOfView();
    ~PointOfView() override;

    void handleEvents() override;
    void update(sf::Time &elapsed) override;
    void render(sf::RenderWindow *pRenderWindow, fd::Matrix44f *view, fd::Vector4f *position) override;
};




#endif // POINT_OF_VIEW
