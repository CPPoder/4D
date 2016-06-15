#ifndef WORLD_HPP
#define WORLD_HPP

#include <vector>


#include "Cuboid.hpp"

#include "Observer.hpp"

#include "CoordinateCross.hpp"



class World
{
private:
    float mSize1, mSize2, mSize3, mSize4; //

    // Objects in the world
    std::vector<Cuboid> mCuboids;

    //The observer
    Observer mObserver;

    // The coordinate cross
    CoordinateCross mCoordinateCross;

    //Variables controlling the sensitivity of the controlling
    float mAlpha;

    //Variable controlling the coloring of the vertices
    float mColorDeepness;



public:



    World();
    ~World();

    void handleEvents();
    void update(sf::Time &elapsed) ;
    void render(sf::RenderWindow *pRenderWindow);

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
