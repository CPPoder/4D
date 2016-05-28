#ifndef CUBOID_HPP
#define CUBOID_HPP

#include "SFML\Graphics.hpp"
#include <vector>
#include "Object.hpp"
#include "ourVectors.hpp"

// Describes a 4D cuboid with generically different lengths of the edges
class Cuboid : public Object
{
private:
    fd::Vector4f mPosition;
    fd::Vector4f mDiagonal; // vector of the diagonal of the cube from the position vector


public:
    Cuboid(fd::Vector4f _position, fd::Vector4f _diagonal);
    ~Cuboid() override;

    std::vector<sf::VertexArray> getEdges();

    void handleEvents() override;
    void update() override;
    void render() override;

    fd::Vector4f getPosition();

};

#endif // CUBOID_HPP
