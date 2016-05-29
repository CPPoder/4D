#ifndef WORLD_HPP
#define WORLD_HPP

#include <vector>

#include "Cuboid.hpp"

#include "Observer.hpp"

class World
{
private:
    float mSize1, mSize2, mSize3, mSize4; //

    // Objects in the world
    std::vector<Cuboid> mCuboids;


    //The observer
    Observer observer;

    //Variables controlling the sensitivity of the controlling
    float alpha;

    //Variables encoding the controlling


public:

    bool mMoveViewA;
    bool mMoveViewD;
    bool mMoveViewW;
    bool mMoveViewS;
    bool mMoveViewY;
    bool mMoveViewX;
    bool mAccelerate;
    bool mDecelerate;

    World();
    ~World();

    void handleEvents();
    void update(sf::Time &elapsed) ;
    void render();




};


#endif
