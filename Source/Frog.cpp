#include "Frog.h"

Frog::Frog(float x, float y)
{
	posx = x;
	posy = y;
	velx = 0.0f;
	vely = 0.0f;
	numMoves = 0;
	moving = false;
	onLog = false;
	reset = false;
	lives = 3;
	if (!FrogTexture.loadFromFile("Frog.png"))
	{
		std::cout << "error loading file" << std::endl;
		return;
	}
	FrogSprite.setTexture(FrogTexture);
	FrogSprite.setOrigin(24.0f, 18.0f);
	FrogSprite.setPosition(posx, posy);
};

void Frog::setDirection(float logVelx)
{
	if (onLog && moving == false)
	{
		velx = logVelx;
		vely = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && moving == false)
	{
		direction = "up";
		FrogSprite.setRotation(0.0f);
		velx = 0.0f;
		vely = -2.0f;
		moving = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && moving == false)
	{
		direction = "down";
		FrogSprite.setRotation(180.0f);
		velx = 0.0f;
		vely = 2.0f;
		moving = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && moving == false)
	{
		direction = "left";
		FrogSprite.setRotation(270.0f);
		velx = -2.0f;
		if (onLog)
		{
			velx = logVelx - 2.0f;
		}
		vely = 0.0f;
		moving = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && moving == false)
	{
		direction = "right";
		FrogSprite.setRotation(90.0f);
		velx = 2.0f;
		if (onLog)
		{
			velx = logVelx + 2.0f;
		}
		vely = 0.0f;
		moving = true;
	}
}

void Frog::move(float logPosy)
{
	sf::Vector2f position = FrogSprite.getPosition();
	if (moving)
	{
		FrogSprite.move(velx, vely);
		numMoves += 2;
	}
	else if (position.y <= logPosy + 10 && position.y >= logPosy - 10 && moving == false)
	{
		FrogSprite.move(velx, vely);
	}
	if (numMoves >= 48 || reset)
	{
		numMoves = 0;
		moving = false;
		reset = false;
	}
}

void Frog::Update(float logVelx, float logPosy)
{
	setDirection(logVelx);
	move(logPosy);
}

bool Frog::loseLife()
{
	FrogSprite.setPosition(320.0f, 456.0f);
	lives--;
	reset = true;
	if (lives <= 0)
	{
		moving = false;
		numMoves = 0;
		return false;
	}
	return true;
}

bool Frog::Win()
{
	FrogSprite.setPosition(320.0f, 456.0f);
	moving = false;
	numMoves = 0;
	return false;
}

int Frog::getLives()
{
	return lives;
}

void Frog::Reset()
{
	lives = 3;
}