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

	sf::FloatRect rect = sprite.getLocalBounds();
	sprite.setOrigin(rect.left + rect.width / 2.f, rect.top + rect.height / 2.f);
	rect = sprite.getLocalBounds();
	//sprite.setPosition(sprite.getPosition() + sf::Vector2f(rect.width / 2.f, rect.height / 2.f));
}

bool Tale::isActive() { return active; }

void Tale::rotate()
{
	sprite.rotate(90.f);
}