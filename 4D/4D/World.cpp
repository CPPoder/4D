#include "stdafx.h"
#include "World.hpp"
#include <iostream>
#include <vector>

//Constructor
World::World()
    : observer(), mAlpha(0.1f)
{
    //Size of the world
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

//Destructor
World::~World()
{

}


void World::handleEvents()
{

}

//Update of all objects and the observer
//Add possibility of objects moving around
void World::update(sf::Time &elapsed)
{
     observer.update(elapsed, mAlpha);
     //objects --> update
}

void World::render()
{

}

//Hand detected moves of the observer to the observer object
//Block A -- D
void World::moveViewA()
{
    observer.mMoveAD = 1;
}
void World::moveViewD()
{
    observer.mMoveAD = -1;
}
void World::stopMoveAD()
{
    observer.mMoveAD = 0;
}

//Block W -- S
void World::moveViewW()
{
    observer.mMoveWS = 1;
}
void World::moveViewS()
{
    observer.mMoveWS = -1;
}
void World::stopMoveWS()
{
    observer.mMoveWS = 0;
}

//Block x -- Y
void World::moveViewX()
{
    observer.mMoveXY = 1;
}
void World::moveViewY()
{
    observer.mMoveXY = -1;
}
void World::stopMoveXY()
{
    observer.mMoveXY = 0;
}

//Block Forward -- Backward
void World::moveForward()
{
    observer.mMoveFB = 1;
}
void World::moveBackward()
{
    observer.mMoveFB = -1;
}
void World::stopMoveFB()
{
    observer.mMoveFB = 0;
}





