#ifndef FRAMEWORK_HPP
#define FRAMEWORK_HPP

#include <iostream>
#include "SFML\Graphics.hpp"


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