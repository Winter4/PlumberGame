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

		for (int i = 0; i < TALES_NUMBER; i++)
			tales[i] = new Tale(window, this->sprite.getPosition() + sf::Vector2f(23 + TALE_SIZE * i + TALE_SIZE / 2.f, 24 + TALE_SIZE / 2.f), talesTexture, TaleType(i + 1));
	}

	void draw();
	sf::FloatRect getRect();
	TaleType processMouseClick(sf::Vector2i mousePosition);
	void highlightTale(TaleType tale);
};

