#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include <iostream>

class Element
{
private:


public:
    Element();
    virtual ~Element();

	virtual void handleEvents() = 0;
	virtual void update() = 0;
	virtual void render() = 0;

};




#endif