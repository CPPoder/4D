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
    float mAlpha;

    //Variables encoding the controlling


public:



    World();
    ~World();

    void handleEvents();
    void update(sf::Time &elapsed) ;
    void render();

    void moveViewA();
    void moveViewD();
    void stopMoveAD();
    void moveViewW();
    void moveViewS();
    void stopMoveWS();
    void moveViewX();
    void moveViewY();
    void stopMoveXY();
    void moveForward();
    void moveBackward();
    void stopMoveFB();




};


#endif
