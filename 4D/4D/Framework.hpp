#ifndef FRAMEWORK_HPP
#define FRAMEWORK_HPP

#include "SFML\Graphics.hpp"

#include <iostream>

#include "Element.hpp"
#include "World.hpp"



class Framework
{
private:
	sf::RenderWindow *pRenderWindow;

	void handleEvents();
	void update();
	void render();
	

public:
	Framework();
	~Framework();

	void run();

};



#endif