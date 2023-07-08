#include "Goal.h"

Goal::Goal(float x, float y)
{
	shape.setSize(sf::Vector2f(640.0f, 48.0f));
	shape.setFillColor(sf::Color::Green);
	shape.setPosition(sf::Vector2f(x, y));
	fillshape1.setSize(sf::Vector2f(56.0f, 40.0f));
	fillshape1.setFillColor(sf::Color::Black);
	fillshape2 = fillshape1;
	fillshape3 = fillshape1;
	fillshape1.setPosition(sf::Vector2f(132.0f, 8.0f));
	fillshape2.setPosition(sf::Vector2f(292.0f, 8.0f));
	fillshape3.setPosition(sf::Vector2f(452.0f, 8.0f));
};