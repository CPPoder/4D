#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include <iostream>

#include "SFML\System.hpp"

class Element
{
private:


public:
    Element();
    virtual ~Element();

	virtual void handleEvents() = 0;
	virtual void update(sf::Time &elapsed) = 0;
	virtual void render() = 0;

};




#endif
