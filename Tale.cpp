#include "Tale.h"

void Tale::draw()
{
	if (active) Entity::draw();
}

bool Tale::contains(sf::Vector2i mousePosition)
{
	return sprite.getGlobalBounds().contains(sf::Vector2f(mousePosition));
}

void Tale::highlight(bool state)
{
	if (state) sprite.setColor(sf::Color::Green);
	else sprite.setColor(sf::Color::White);
}

void Tale::setTale(TaleType tale)
{
	active = true;
	switch (tale) {
	case TaleType::NONE:
		active = false;
		sprite.setTextureRect(sf::IntRect(0, 0, TALE_SIZE, TALE_SIZE));
		break;

	case TaleType::Straight:
		sprite.setTextureRect(sf::IntRect(0, 0, TALE_SIZE, TALE_SIZE));
		break;

	case TaleType::Angle:
		sprite.setTextureRect(sf::IntRect(TALE_SIZE, 0, TALE_SIZE, TALE_SIZE));
		break;

	case TaleType::X:
		sprite.setTextureRect(sf::IntRect(TALE_SIZE * 2, 0, TALE_SIZE, TALE_SIZE));
		break;

	case TaleType::T:
		sprite.setTextureRect(sf::IntRect(TALE_SIZE * 3, 0, TALE_SIZE, TALE_SIZE));
		break;
	}
}

bool Tale::isActive() { return active; }