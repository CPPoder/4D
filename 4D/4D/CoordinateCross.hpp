#ifndef COORDINATE_CROSS
#define COORDINATE_CROSS
#include "Object.hpp"
#include "ourVectors.hpp"
#include "ourMatrices.hpp"
#include "SFML/Graphics.hpp"

class CoordinateCross : public Object
{
private:
    sf::VertexArray mVertexArray;
    sf::Vector2f mPosition2D;



public:
    CoordinateCross();
    ~CoordinateCross() override;


    void handleEvents() override;
    void update(sf::Time &elapsed) override;
    void render(sf::RenderWindow *pRenderWindow, fd::Matrix44f *view, fd::Vector4f *position) override;
    void fillVertexArray(float colorDeepness);

};




#endif // COORDINATE_CROSS
