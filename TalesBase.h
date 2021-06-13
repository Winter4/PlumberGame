#pragma once
#include "Entity.h"
#include "Tale.h"

#define TALES_NUMBER 4

class TalesBase : public Entity {
private:
	Tale** tales;
	TaleType activeTale;

public:
	TalesBase(sf::RenderWindow* window, sf::Vector2f position, const sf::Texture& texture, const sf::Texture& talesTexture)
		: Entity(window, position, texture)
	{
		activeTale = TaleType::NONE;

		tales = new Tale * [TALES_NUMBER];
		tales[0] = new Tale(window, this->sprite.getPosition() + sf::Vector2f(23 + 83 * 0, 24), talesTexture, TaleType::Straight);
		tales[1] = new Tale(window, this->sprite.getPosition() + sf::Vector2f(23 + 83 * 1, 24), talesTexture, TaleType::Angle);
		tales[2] = new Tale(window, this->sprite.getPosition() + sf::Vector2f(23 + 83 * 2, 24), talesTexture, TaleType::T);
		tales[3] = new Tale(window, this->sprite.getPosition() + sf::Vector2f(23 + 83 * 3, 24), talesTexture, TaleType::X);
	}

	void draw();
	sf::FloatRect getRect();
	TaleType processMouseClick(sf::Vector2i mousePosition);
	void highlightTale(TaleType tale);
};

