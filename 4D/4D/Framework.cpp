#include "stdafx.h"
#include "Framework.hpp"

//Constructor
Framework::Framework()
    : mWorld()
{
	pRenderWindow = new sf::RenderWindow(sf::VideoMode(1440, 900), "4D Engine");
	pRenderWindow->setFramerateLimit(60u);

	pArialFont = new sf::Font;
	pArialFont->loadFromFile("./arial.ttf");

	mFPSText.setFont(*pArialFont);
	mFPSText.setPosition(sf::Vector2f(2.f, 0.f));
	mFPSText.setString("FPS: ");
	mFPSText.setCharacterSize(12u);
	mFPSText.setFillColor(sf::Color::White);

	mUtilizationText.setFont(*pArialFont);
	mUtilizationText.setPosition(sf::Vector2f(2.f, 10.f));
	mUtilizationText.setString("Util: ");
	mUtilizationText.setCharacterSize(12u);
	mUtilizationText.setFillColor(sf::Color::White);

	mFPSClock.restart();
}

//Destructor
Framework::~Framework()
{
	delete pRenderWindow;
	pRenderWindow = nullptr;

	delete pArialFont;
	pArialFont = nullptr;

}


//HandleEvents, Update, Render
void Framework::handleEvents()
{
    readKeyboard();
	sf::Event mEvent;
	while (pRenderWindow->pollEvent(mEvent))
	{
		if (mEvent.type == sf::Event::EventType::Closed)
		{
			pRenderWindow->close();
		}
		if (mEvent.type == sf::Event::EventType::KeyReleased)
		{
			if (mEvent.key.code == sf::Keyboard::Key::Space)
			{
				mShowFPS = !mShowFPS;
			}
		}
	}
}

void Framework::update()
{
    mWorld.update(mFrametime);
}

void Framework::render()
{
	pRenderWindow->clear();
	mWorld.render(pRenderWindow);
	if (mShowFPS)
	{
		pRenderWindow->draw(mFPSText);
		pRenderWindow->draw(mUtilizationText);
	}
	sf::Time timeBeforeRendering = mFPSClock.getElapsedTime();
	pRenderWindow->display();
	mRenderTimePerFrame = mFPSClock.getElapsedTime() - timeBeforeRendering;
}


//Controlling is done by:
//Left - Right (left - right): x1
//W - S (up - down): x2
//A - D ( ??    ) : y
//Up - Down (move forward - move backwards) : v

//Read out the input given by pressing keys on the keyboard
void Framework::readKeyboard()
{
    //Block A - D --> Moving to the left / right
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

    //Block W - S --> Moving up / down
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

    //Block Q - E --> Moving in the fourth dimension
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && !sf::Keyboard::isKeyPressed(sf::Keyboard::E))
    {
        mWorld.moveViewX();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        mWorld.moveViewY();
    }
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::E) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        mWorld.stopMoveXY();
    }

    //Block F - B --> Moving forward and backward
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

    //Block Left - Right --> Move Left - Right
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        mWorld.moveLeft();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        mWorld.moveRight();
    }
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        mWorld.stopMoveLR();
    }


}


//Determine FPS
void Framework::determineFrametime()
{
	static sf::Time timeSinceLastSecond(sf::seconds(0.f));
	static unsigned int framesSinceLastSecond(0u);
	static sf::Time renderTimeSinceLastSecond(sf::seconds(0.f));

	mFrametime = mFPSClock.restart();
	timeSinceLastSecond += mFrametime;
	renderTimeSinceLastSecond += mRenderTimePerFrame;
	++framesSinceLastSecond;

	if (timeSinceLastSecond > sf::seconds(1.f))
	{
		mFPS = framesSinceLastSecond;
		mFPSText.setString("FPS: " + std::to_string(mFPS));

		mUtilization = (timeSinceLastSecond - renderTimeSinceLastSecond).asSeconds();
		mUtilizationText.setString("Util: " + std::to_string(static_cast<int>(mUtilization * 100.f)) + "%");

		framesSinceLastSecond = 0u;
		timeSinceLastSecond = sf::seconds(0.f);
		renderTimeSinceLastSecond = sf::seconds(0.f);
	}
}


//Run
void Framework::run()
{
	while (pRenderWindow->isOpen())
	{
		determineFrametime();
		handleEvents();
		update();
		render();
	}
}
