#include "Grass.h"

Grass::Grass(float x, float y)
{
	shape.setSize(sf::Vector2f(640.0f, 48.0f));
	shape.setFillColor(sf::Color::Magenta);
	shape.setPosition(sf::Vector2f(x, y));
};