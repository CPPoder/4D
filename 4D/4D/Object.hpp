#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "element.hpp"
#include "ourVectors.hpp"
#include "ourMatrices.hpp"


class Object : public Element
{
private:
    //fd::Vector4f mPosition;

public:
    //Variable controlling the centering of the drawing
    fd::Vector2f mGlobalOffset;

    //Variables controlling the coloring
    float mColorDeepness;

    //Controlling the zoom factor; higher zoom means a smaller screen but hopefully less strange effects
    float zoom;

    //Controlling the zoom
    fd::Vector2f alpha;

    //Controlling the two focus points
    fd::Vector2f f1;
    fd::Vector2f f2;
    //For pureColor projection
    fd::Vector2f f;

    //Controlling the way, in which things get smaller when moving away
    float z0;

    //Variables controlling the drawing style
    int mProjectionManner;  // Describes which projection is used: 0: pureColor -    1: spatial -    2: parallel  - see documentation
    bool mRestrictVisibility;


    //Konst/ Destruktor
    Object();
    virtual ~Object();

    //"Object" functions
    virtual void handleEvents() = 0;
    virtual void update(sf::Time &elapsed) = 0;
    virtual void render(sf::RenderWindow *pRenderWindow, fd::Matrix44f *view, fd::Vector4f *position) = 0;

    //View transformation
    fd::Vector4f transformToObserversView(fd::Vector4f *positionObserver, fd::Matrix44f *viewObserver, fd::Vector4f point);

    //Projection methods
    fd::Vector2f parallelProjection(fd::Vector4f pointIn);

    fd::Vector2f spatialProjection(fd::Vector4f pointIn);

    fd::Vector2f pureColorProjection(fd::Vector4f pointIn);

    //Coloring methods
    int colorScaling(float xIn, float colorDeepness);

    sf::Color projectionColor(fd::Vector4f xIn, float colorDeepness);

    sf::Color colorPureColor(fd::Vector4f xIn);

    //Methods checking for visibility

    //Input: An edge, whose coordinates may be smaller than 0 in dim 3,4 --> they shall not be projected, as they are behind the observer
    //Output: Edge, which is the visible part of the input
    fd::Matrix42f correctEdge(fd::Vector4f vectorIn1, fd::Vector4f vectorIn2); //Correcting an edge

    bool isPointVisible(fd::Vector4f point); //Checks for a point



};

#endif // OBJECT_HPP
