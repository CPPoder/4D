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
	mWorld.render(pRenderWindow);
	pRenderWindow->display();
}

//Controlling is done by:
//A - D (left - right): x1
//W - S (up - down): x2
//X - Y ( ??    ) : y
//Up - Down (move forward - move backwards) : v

//Read out the input given by pressing keys on the keyboard
void Framework::readKeyboard()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        mWorld.moveViewA();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        mWorld.moveViewD();
    }
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        mWorld.stopMoveAD();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        mWorld.moveViewW();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        mWorld.moveViewS();
    }
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        mWorld.stopMoveWS();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
    {
        mWorld.moveViewX();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y) && !sf::Keyboard::isKeyPressed(sf::Keyboard::X))
    {
        mWorld.moveViewY();
    }
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Y) && !sf::Keyboard::isKeyPressed(sf::Keyboard::X))
    {
        mWorld.stopMoveXY();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        mWorld.moveForward();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        mWorld.moveBackward();
    }
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        mWorld.stopMoveFB();
    }
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
