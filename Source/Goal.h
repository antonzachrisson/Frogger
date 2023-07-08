#pragma once

#include "SFML/Graphics.hpp"

class Goal
{
public:
	Goal(float x, float y);
	sf::RectangleShape shape;
	sf::RectangleShape fillshape1;
	sf::RectangleShape fillshape2;
	sf::RectangleShape fillshape3;
};
