#include "Game.h"


Game::Game(unsigned int &screenWidth, unsigned int &screenHeight, const char* &title)
{
	screenWidth = 640;
	screenHeight = 480;
	title = "The Game";
	srand(static_cast<unsigned int>(time(nullptr)));
	Obstacle* obstacle = new Obstacle(0, true);
	obstacleptr = obstacle;
	spawnTime2 = 0;
	spawnTime3 = 0;
	spawnTime4 = 0;
	spawnTime5 = 0;
	spawnTime7 = 0;
	spawnTime8 = 0;
	spawnTime9 = 0;
	timeToSpawnCars = 0;
	timeToSpawnLogs = 0;
	logVelx = 0.0f;
	logPosy = 0.0f;
	playing = false;

	if (!font.loadFromFile("Bright Star.ttf"))
	{
		std::cout << "error loading file" << std::endl;
		return;
	}
	strMenu = "PRESS SPACE TO START";
	Menu.setFont(font);
	Menu.setCharacterSize(15);
	Menu.setFillColor(sf::Color::White);
	Menu.setString(strMenu);
	sf::Rect<float> rect = Menu.getLocalBounds();
	Menu.setPosition((640.0f - rect.width) / 2, 200.0f);
	lives.setFont(font);
	lives.setCharacterSize(15);
	lives.setFillColor(sf::Color::Green);
	lives.setPosition(0.0f, 450.0f);
};

Game::~Game()
{
	obstacleptr->cars.clear();
    delete obstacleptr;
}

bool Game::Update(float deltaTime)
{
	if (playing)
	{
		Collision();
		spawnObject();
		frogptr.Update(logVelx, logPosy);
		obstacleptr->moveObstacles();
		removeObject();
		setLives();
	}
	else
	{
		menu();
		frogptr.Reset();
	}
	return true;
}

void Game::Draw(sf::RenderWindow& window)
{
	if (playing)
	{
		window.draw(startptr.shape);
		window.draw(middleptr.shape);
		window.draw(goalptr.shape);
		window.draw(goalptr.fillshape1);
		window.draw(goalptr.fillshape2);
		window.draw(goalptr.fillshape3);
		for (int i = 0; i < obstacleptr->getNumCars(); i++)
		{
			window.draw(obstacleptr->cars[i]->CarSprite);
		}
		window.draw(frogptr.FrogSprite);
		window.draw(lives);
	}
	else
	{
		window.draw(Menu);
	}
}

void Game::menu()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		playing = true;
	}
}

void Game::removeObject()
{
	obstacleptr->removeObstacles();
}

void Game::spawnObject()
{
	spawnTime2++;
	spawnTime3++;
	spawnTime4++;
	spawnTime5++;
	spawnTime7++;
	spawnTime8++;
	spawnTime9++;
	if (spawnTime2 > timeToSpawnLogs)
	{
		obstacleptr->spawnObstacle(2, false);
		spawnTime2 = 0;
		timeToSpawnLogs = rand() % 500 + 400;
	}
	if (spawnTime3 > timeToSpawnLogs)
	{
		obstacleptr->spawnObstacle(3, false);
		spawnTime3 = 0;
		timeToSpawnLogs = rand() % 500 + 400;
	}
	if (spawnTime4 > timeToSpawnLogs)
	{
		obstacleptr->spawnObstacle(4, false);
		spawnTime4 = 0;
		timeToSpawnLogs = rand() % 500 + 400;
	}
	if (spawnTime5 > timeToSpawnLogs)
	{
		obstacleptr->spawnObstacle(5, false);
		spawnTime5 = 0;
		timeToSpawnLogs = rand() % 500 + 400;
	}
	if (spawnTime7 > timeToSpawnCars)
	{
		obstacleptr->spawnObstacle(7, true);
		spawnTime7 = 0;
		timeToSpawnCars = rand() % 300 + 200;
	}
	if (spawnTime8 > timeToSpawnCars)
	{
		obstacleptr->spawnObstacle(8, true);
		spawnTime8 = 0;
		timeToSpawnCars = rand() % 300 + 200;
	}
	if (spawnTime9 > timeToSpawnCars)
	{
		obstacleptr->spawnObstacle(9, true);
		spawnTime9 = 0;
		timeToSpawnCars = rand() % 300 + 200;
	}
}

void Game::reset()
{
	playing = frogptr.loseLife();
}

void Game::Collision()
{
	sf::Rect<float> FrogRect = frogptr.FrogSprite.getGlobalBounds();
	sf::Vector2f position = frogptr.FrogSprite.getPosition();
	frogptr.onLog = false;

	obstacleptr->addColliders();

	for (int i = 0; i < obstacleptr->getNumCars(); i++)
	{
		if (obstacleptr->Colliders[i].intersects(FrogRect) && obstacleptr->Type[i])
		{
			reset();
		}
		else if (obstacleptr->Colliders[i].intersects(FrogRect) && obstacleptr->Type[i] == false)
		{
			frogptr.onLog = true;
			logVelx = obstacleptr->cars[i]->getVelx();
			sf::Vector2f logPos = obstacleptr->cars[i]->CarSprite.getPosition();
			logPosy = logPos.y;
		}
	}
	if (frogptr.moving == false && position.y > 48.0f && position.y < 240.0f && frogptr.onLog == false)
	{
		reset();
	}
	else if (position.y < 48.0f)
	{
		if (position.x < 156 || position.x > 484)
		{
			reset();
		}
		else if (position.x > 212 && position.x < 268)
		{
			reset();
		}
		else if (position.x > 324 && position.x < 428)
		{
			reset();
		}
		else
		{
			playing = frogptr.Win();
		}
	}
	obstacleptr->Colliders.clear();
	obstacleptr->Type.clear();
}

void Game::setLives()
{
	strLives.clear();
	for (int i = 0; i < frogptr.getLives(); i++)
	{
		strLives.push_back('A');
	}
	lives.setString(strLives);
}
