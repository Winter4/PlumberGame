#pragma once
#include "Entity.h"
#include "Tale.h"
#include "TexturesID.h"

#define FIELD_LENGTH 10

class Field : public Entity {
private:
	Tale*** tales;

public:
	Field(sf::RenderWindow* window, sf::Vector2f position, const sf::Texture& texture, const sf::Texture& talesTexture)
		: Entity(window, position, texture)
	{
		tales = new Tale * *[FIELD_LENGTH];
		for (int i = 0; i < FIELD_LENGTH; i++) {
			tales[i] = new Tale * [FIELD_LENGTH];

			for (int j = 0; j < FIELD_LENGTH; j++)
				tales[i][j] = new Tale(window, position + sf::Vector2f(23 + TALE_SIZE * j, 25 + TALE_SIZE * i), talesTexture, TaleType::NONE);
		}
	}

	void draw();
	void processMouseClick(sf::Vector2i mousePosition, TaleType activeTale);
};

