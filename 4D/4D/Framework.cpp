#include "stdafx.h"
#include "Framework.hpp"

//Constructor
Framework::Framework()
{
	pRenderWindow = new sf::RenderWindow(sf::VideoMode(1440, 900), "4D Engine");
	pWorld = new World();
}

//Destructor
Framework::~Framework()
{
	delete pRenderWindow;
	pRenderWindow = nullptr;

	delete pWorld;
	pWorld = nullptr;
}


//HandleEvents, Update, Render
void Framework::handleEvents()
{
	sf::Event mEvent;
	while (pRenderWindow->pollEvent(mEvent))
	{
		if (mEvent.type == sf::Event::EventType::Closed)
		{
			pRenderWindow->close();
		}
	}
}

void Framework::update()
{

}

void Framework::render()
{
	pRenderWindow->clear();
	//pRenderWindow->draw();
	pRenderWindow->display();
}


//Run
void Framework::run()
{
	while (pRenderWindow->isOpen())
	{
		handleEvents();
		update();
		render();
	}
}
