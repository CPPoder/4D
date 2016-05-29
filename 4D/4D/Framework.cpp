#include "stdafx.h"
#include "Framework.hpp"

//Constructor
Framework::Framework()
    : mWorld()
{
	pRenderWindow = new sf::RenderWindow(sf::VideoMode(1440, 900), "4D Engine");
}

//Destructor
Framework::~Framework()
{
	delete pRenderWindow;
	pRenderWindow = nullptr;

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
    //Handle time
    sf::Time elapsed = clock.restart();
    mWorld.update(elapsed);
}

void Framework::render()
{
	pRenderWindow->clear();
	//pRenderWindow->draw();
	pRenderWindow->display();
}

//Controlling is done by:
//A - D (left - right): x1
//W - S (up - down): x2
//X - Y ( ??    ) : y
//Up - Down (accelerate, decelerate) : d/dt v

//Read out the input given by pressing keys on the keyboard
void Framework::readKeyboard()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        mWorld.mMoveViewA = true;
        mWorld.mMoveViewD = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        mWorld.mMoveViewD = true;
        mWorld.mMoveViewA = false;
    }

    //To be continued!
    //Should be easy to simplify: Introduce a structure with the eight keys and the possibility to iterate them

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
