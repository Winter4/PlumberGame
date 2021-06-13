#pragma once
#include "Entity.h"
#include "TexturesID.h"

class Tale : public Entity {
private:

public:
	Tale(sf::RenderWindow* window, sf::Vector2f position, const sf::Texture& texture, TaleType taleType)
		: Entity(window, position, texture)
	{
		switch (taleType) {
		case TaleType::Straight:
			sprite.setTextureRect(sf::IntRect(0, 0, 83, 83));
			break;

		case TaleType::Angle:
			sprite.setTextureRect(sf::IntRect(83, 0, 83, 83));
			break;

		case TaleType::T:
			sprite.setTextureRect(sf::IntRect(166, 0, 83, 83));
			break;

		case TaleType::X:
			sprite.setTextureRect(sf::IntRect(249, 0, 83, 83));
			break;
		}
	}

	void draw();
	bool processMouseClick(sf::Vector2i mousePosition);
	void highlight(bool state);
};

