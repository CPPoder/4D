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
	World mWorld;

	//Fonts
	sf::Font* pArialFont;

	//Frametime & Utilization
	sf::Clock mFPSClock;
	sf::Time mFrametime = sf::seconds(0.f);
	sf::Time mRenderTimePerFrame = sf::seconds(0.f);
	unsigned int mFPS = 0;
	float mUtilization = 0.f;
	sf::Text mFPSText;
	sf::Text mUtilizationText;
	bool mShowFPS = true;


	void determineFrametime();
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
