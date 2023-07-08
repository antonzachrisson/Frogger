#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>

class Frog
{
private:
	float posx;
	float posy;
	float velx;
	float vely;
	int lives;
	bool reset;
	std::string direction;
	int numMoves;
	sf::Texture FrogTexture;
	void move(float logPosy);
	void setDirection(float logVelx);
public:
	Frog(float x, float y);
	void Update(float logVelx, float logPosy);
	bool loseLife();
	bool Win();
	int getLives();
	void Reset();
	sf::Sprite FrogSprite;
	bool onLog;
	bool moving;
};
