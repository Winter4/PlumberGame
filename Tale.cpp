#include "Tale.h"

void Tale::draw()
{
	Entity::draw();
}

bool Tale::processMouseClick(sf::Vector2i mousePosition)
{
	return sprite.getGlobalBounds().contains(sf::Vector2f(mousePosition));
}

void Tale::highlight(bool state)
{
	if (state) sprite.setColor(sf::Color::Black);
	else sprite.setColor(sf::Color::White);
}