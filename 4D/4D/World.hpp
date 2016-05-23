#ifndef WORLD_HPP
#define WORLD_HPP

#include "Element.hpp"

class World : public Element
{
private:
    double mWorldSize; //




public:
    World();
    ~World() override;

	void handleEvents() override;
	void update() override;
	void render() override;



};


#endif
