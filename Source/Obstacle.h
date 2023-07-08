#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>
#include <time.h>

class Obstacle
{
private:
	float posx;
	float posy;
	float velx;
	float vely;
	int variant;
	int numCars;
	int lane;
	bool isCar;
	sf::Texture CarTexture;
	Obstacle* temp;
public:
	Obstacle(int lane_, bool isCar_);
	sf::Sprite CarSprite;
	std::vector<Obstacle*> cars;
	std::vector<sf::Rect<float>> Colliders;
	std::vector<bool> Type;
	void move();
	void moveObstacles();
	int getNumCars();
	void removeObstacles();
	void spawnObstacle(int lane_, bool isCar_);
	void addColliders();
	float getVelx();
};