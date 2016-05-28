#ifndef WORLD_HPP
#define WORLD_HPP

#include <vector>

#include "Element.hpp"

#include "Cuboid.hpp"

#include "Observer.hpp"

class World : public Element
{
private:
    float mSize1, mSize2, mSize3, mSize4; //

    // Objects in the world
    std::vector<Cuboid> mCuboids;


    //The observer
    Observer observer();





public:
    World();
    ~World() override;

    void handleEvents() override;
    void update() override;
    void render() override;



};


#endif
