#ifndef FRAMEWORK_HPP
#define FRAMEWORK_HPP

#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"

#include <iostream>

#include "ourVectors.hpp"
#include "ourMatrices.hpp"
#include "Element.hpp"
#include "World.hpp"



class Framework
{
private:
	sf::RenderWindow *pRenderWindow;
	sf::Clock clock;
	World mWorld;


	void handleEvents();
	void update();
	void render();
	void readKeyboard();


public:
	Framework();
	~Framework();

	void run();

};



#endif
