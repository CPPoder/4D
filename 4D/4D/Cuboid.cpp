#include "SFML\Graphics.hpp"
#include <vector>
#include "ourVectors.hpp"
#include "Cuboid.hpp"

//Constructor
Cuboid::Cuboid(fd::Vector4f _position, fd::Vector4f _diagonal)
    : mPosition(_position), mDiagonal(_diagonal)
{

}

//Destructor
Cuboid::~Cuboid()
{

}

/*std::vector<sf::VertexArray> getEdges()
{

}
*/

void Cuboid::handleEvents()
{

}

void Cuboid::render()
{

}

void Cuboid::update(sf::Time &elapsed)
{

}

fd::Vector4f Cuboid::getPosition()
{
    return(Cuboid::mPosition);
}

