#pragma once

#include "SFML/Graphics.hpp"
#include "Obstacle.h"
#include "Frog.h"
#include "Goal.h"
#include "Grass.h"

class Game
{
public:
	Game(unsigned int& screenWidth, unsigned int& screenHeight, const char*& title);
	~Game();
	/// Return Value
	/// true = Continue to run program
	/// false = Quits program
	bool Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
private:
	void removeObject();
	void spawnObject();
	void Collision();
	void reset();
	void menu();
	void setLives();
	int spawnTime2;
	int spawnTime3;
	int spawnTime4;
	int spawnTime5;
	int spawnTime7;
	int spawnTime8;
	int spawnTime9;
	int timeToSpawnCars;
	int timeToSpawnLogs;
	float logVelx;
	float logPosy;
	bool playing;
	Obstacle* obstacleptr = nullptr;
	Frog frogptr = Frog(320.0f, 456.0f);
	Grass startptr = Grass(0.0f, 432.0f);
	Grass middleptr = Grass(0.0f, 240.0f);
	Goal goalptr = Goal(0.0f, 0.0f);

	sf::Font font;
	sf::Text Menu;
	sf::Text lives;
	std::string strMenu;
	std::string strLives;
};