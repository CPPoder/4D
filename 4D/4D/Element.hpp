#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include <iostream>

#include "SFML\System.hpp"
#include "ourMatrices.hpp"
#include "ourVectors.hpp"

class Element
{
private:


public:
    Element();
    virtual ~Element();

	virtual void handleEvents() = 0;
	virtual void update(sf::Time &elapsed) = 0;
	virtual void render(sf::RenderWindow *pRenderWindow, fd::Matrix44f *view, fd::Vector4f *position) = 0;

};




#endif
