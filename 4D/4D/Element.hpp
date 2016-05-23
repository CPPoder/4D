#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include <iostream>

class Element
{


private:
    virtual void handleEvents() = 0;
	virtual void update();
	virtual void render();


public:
    Element();
    ~Element();


}

#endif
