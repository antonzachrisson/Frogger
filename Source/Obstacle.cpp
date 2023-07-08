#include "Obstacle.h"

Obstacle::Obstacle(int lane_, bool isCar_)
{
	srand(static_cast<unsigned int>(time(nullptr)));
	variant = rand() % 3;
	numCars = 0;
	lane = lane_;
	isCar = isCar_;
	posx = 0.0f;
	posy = 0.0f;
	velx = 0.0f;
	vely = 0.0f;
	temp = nullptr;
	if (isCar)
	{
		if (variant == 0)
		{
			if (!CarTexture.loadFromFile("Car0.png"))
			{
				std::cout << "error loading file" << std::endl;
				return;
			}
			CarSprite.setOrigin(38.0f, 20.0f);
		}
		else if (variant == 1)
		{
			if (!CarTexture.loadFromFile("Car1.png"))
			{
				std::cout << "error loading file" << std::endl;
				return;
			}
			CarSprite.setOrigin(39.0f, 20.0f);
		}
		else if (variant == 2)
		{
			if (!CarTexture.loadFromFile("Car2.png"))
			{
				std::cout << "error loading file" << std::endl;
				return;
			}
			CarSprite.setOrigin(39.5f, 20.0f);
		}
	}

	else if (isCar == false)
	{
		if (!CarTexture.loadFromFile("Log.png"))
		{
			std::cout << "error loading file" << std::endl;
			return;
		}
		CarSprite.setOrigin(95.0f, 20.0f);
	}
	
	CarSprite.setTexture(CarTexture);
	if (lane == 2)
	{
		posx = 0.0f;
		posy = 24.0f + (48.0f * (lane - 1));
		vely = 0.0f;
		velx = 1.1f;
	}
	else if (lane == 3)
	{
		posx = 640.0f;
		posy = 24.0f + (48.0f * (lane - 1));
		vely = 0.0f;
		velx = -0.9f;
		CarSprite.setRotation(180.0f);
	}
	else if (lane == 4)
	{
		posx = 0.0f;
		posy = 24.0f + (48.0f * (lane - 1));
		vely = 0.0f;
		velx = 0.7f;
	}
	else if (lane == 5)
	{
		posx = 640.0f;
		posy = 24.0f + (48.0f * (lane - 1));
		vely = 0.0f;
		velx = -0.5f;
	}
	else if (lane == 7)
	{
		posx = 0.0f;
		posy = 24.0f + (48.0f * (lane - 1));
		vely = 0.0f;
		velx = 1.1f;
	}
	else if (lane == 8)
	{
		posx = 640.0f;
		posy = 24.0f + (48.0f * (lane - 1));
		vely = 0.0f;
		velx = -0.9f;
		CarSprite.setRotation(180.0f);
	}
	else if (lane == 9)
	{
		posx = 0.0f;
		posy = 24.0f + (48.0f * (lane - 1));
		vely = 0.0f;
		velx = 0.7f;
	}

	CarSprite.setPosition(posx, posy);
};

void Obstacle::move()
{
	CarSprite.move(velx, vely);
}

void Obstacle::moveObstacles()
{
	for (int i = 0; i < numCars; i++)
	{
		cars[i]->move();
	}
}

int Obstacle::getNumCars()
{
	return numCars;
}

void Obstacle::removeObstacles()
{
	for (int i = 0; i < numCars; i++)
	{
		sf::Vector2f position = cars[i]->CarSprite.getPosition();
		if (position.x > 680.0f || position.x < -40.0f)
		{
			temp = cars[i];
			std::vector<Obstacle*>::size_type index = numCars;
			cars[i] = cars[index - 1];
			cars[index - 1] = temp;
			cars.pop_back();
			numCars--;
		}
	}
}

void Obstacle::spawnObstacle(int lane_, bool isCar_)
{
	cars.push_back(new Obstacle(lane_, isCar_));
	numCars++;
}

void Obstacle::addColliders()
{
	for (int i = 0; i < numCars; i++)
	{
		Colliders.push_back(cars[i]->CarSprite.getGlobalBounds());
		Type.push_back(cars[i]->isCar);
	}
}

float Obstacle::getVelx()
{
	return velx;
}