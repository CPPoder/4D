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

    void render(sf::RenderWindow *pRenderWindow, fd::Matrix44f *view, fd::Vector4f *position, float colorDeepness) override;
    void fillVertexArray();

};




#endif // COORDINATE_CROSS
