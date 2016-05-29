#include "stdafx.h"
#include "World.hpp"
#include <iostream>
#include <vector>

World::World()
    : observer(), alpha(0.1f)
{
    //Default standard while developing
    mSize1 = 100.f;
    mSize2 = 100.f;
    mSize3 = 100.f;
    mSize4 = 100.f;

    //Construct a simple cuboid
    std::vector<float> mTemp (4, 10.f);
    fd::Vector4f mTemp4f(mTemp);
    mCuboids.push_back(Cuboid(mTemp4f, mTemp4f));


}


World::~World()
{

}


void World::handleEvents()
{

}

void World::update(sf::Time &elapsed)
{
     //Give input of controlling to observer
     //To be continued
}

void World::render()
{

}
