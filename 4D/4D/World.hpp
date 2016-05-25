#ifndef WORLD_HPP
#define WORLD_HPP

#include <vector>

#include "Element.hpp"

#include "Cuboid.hpp"

class World : public Element
{
private:
    float mSize1, mSize2, mSize3, mSize4; //

    std::vector<Cuboid> mCuboids;




public:
    World(float _size1, float _size2, float _size3, float _size4);
    ~World() override;

    void handleEvents() override;
    void update() override;
    void render() override;



};


#endif
