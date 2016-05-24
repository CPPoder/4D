#ifndef WORLD_HPP
#define WORLD_HPP

#include "Element.hpp"

class World : public Element
{
private:
    float mSize1, mSize2, mSize3, mSize4; //




public:
    World();
    ~World() override;

    void handleEvents() override;
    void update() override;
    void render() override;



};


#endif
