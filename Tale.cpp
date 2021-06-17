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
		watered = false;

		exits[0][0] = 0;
		exits[0][1] = 0;
		exits[1][0] = 0;
		exits[1][1] = 0;
		sprite.setTextureRect(sf::IntRect(0, 0, TALE_SIZE, TALE_SIZE));
		break;

	case TaleType::Straight:
		sprite.setTextureRect(sf::IntRect(0, 0, TALE_SIZE, TALE_SIZE));
		exits[0][0] = 1;
		exits[0][1] = 0;
		exits[1][0] = 0;
		exits[1][1] = 1;
		break;

	case TaleType::Angle:
		sprite.setTextureRect(sf::IntRect(TALE_SIZE, 0, TALE_SIZE, TALE_SIZE));
		exits[0][0] = 1;
		exits[0][1] = 1;
		exits[1][0] = 0;
		exits[1][1] = 0;
		break;

	case TaleType::X:
		sprite.setTextureRect(sf::IntRect(TALE_SIZE * 2, 0, TALE_SIZE, TALE_SIZE));
		exits[0][0] = 1;
		exits[0][1] = 1;
		exits[1][0] = 1;
		exits[1][1] = 1;
		break;

	case TaleType::T:
		sprite.setTextureRect(sf::IntRect(TALE_SIZE * 3, 0, TALE_SIZE, TALE_SIZE));
		exits[0][0] = 1;
		exits[0][1] = 0;
		exits[1][0] = 1;
		exits[1][1] = 1;
		break;
	}

	sf::FloatRect rect = sprite.getLocalBounds();
	sprite.setOrigin(rect.left + rect.width / 2.f, rect.top + rect.height / 2.f);
	rect = sprite.getLocalBounds();
	sprite.setRotation(0);
}

bool Tale::isActive() { return active; }

void Tale::rotate()
{
	sprite.rotate(90.f);

	int tmp;
	tmp = exits[0][0];

	exits[0][0] = exits[1][0];
	exits[1][0] = exits[1][1];
	exits[1][1] = exits[0][1];
	exits[0][1] = tmp;
}

bool Tale::connected(Side side)
{
	bool result = false;

	switch (side) {
	case Side::Left:
		if (exits[0][0]) result = true;
		break;

	case Side::Top:
		if (exits[0][1]) result = true;
		break;

	case Side::Right:
		if (exits[1][1]) result = true;
		break;

	case Side::Bot:
		if (exits[1][0]) result = true;
		break;
	}

	return result;
}

bool Tale::isWatered() { return watered; }
void Tale::fill() { 
	watered = true; 
	sprite.setColor(sf::Color::Blue);
}