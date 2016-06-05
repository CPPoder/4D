#include "stdafx.h"
#include "World.hpp"
#include <iostream>
#include <vector>

//Constructor
World::World()
    : mObserver(), mAlpha(0.1f)
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
     mObserver.update(elapsed, mAlpha);
     //objects --> update
}

void World::render(sf::RenderWindow *pRenderWindow)
{
    //Iterate over the objects and call their render functions
    fd::Matrix44f* fView = mObserver.getMView();
    fd::Vector4f* fPosition = mObserver.getMPosition();

    for (Cuboid cCuboid : mCuboids)
    {
        cCuboid.render(pRenderWindow, fView, fPosition);
        mObserver.render();
    }
}

//Hand detected moves of the observer to the observer object
//Block A -- D
void World::moveViewA()
{
    mObserver.mMoveAD = 1;
}
void World::moveViewD()
{
    mObserver.mMoveAD = -1;
}
void World::stopMoveAD()
{
    mObserver.mMoveAD = 0;
}

//Block W -- S
void World::moveViewW()
{
    mObserver.mMoveWS = 1;
}
void World::moveViewS()
{
    mObserver.mMoveWS = -1;
}
void World::stopMoveWS()
{
    mObserver.mMoveWS = 0;
}

//Block x -- Y
void World::moveViewX()
{
    mObserver.mMoveXY = 1;
}
void World::moveViewY()
{
    mObserver.mMoveXY = -1;
}
void World::stopMoveXY()
{
    mObserver.mMoveXY = 0;
}

//Block Forward -- Backward
void World::moveForward()
{
    mObserver.mMoveFB = 1;
}
void World::moveBackward()
{
    mObserver.mMoveFB = -1;
}
void World::stopMoveFB()
{
    mObserver.mMoveFB = 0;
}





