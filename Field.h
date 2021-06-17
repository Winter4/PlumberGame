#pragma once
#include "Entity.h"
#include "Tale.h"
#include "TexturesID.h"
#include <iostream>

#define FIELD_LENGTH 10

class Field : public Entity {
private:
	Tale*** tales;
	sf::Vector2i activeTale;
	int waterEnter;
	int waterExit;

public:
	Field(sf::RenderWindow* window, sf::Vector2f position, const sf::Texture& texture, const sf::Texture& talesTexture, int enterToSet, int exitToSet)
		: Entity(window, position, texture)
	{
		activeTale = { -1, -1 };
		waterEnter = enterToSet;
		waterExit = exitToSet;

		tales = new Tale * *[FIELD_LENGTH];
		for (int i = 0; i < FIELD_LENGTH; i++) {
			tales[i] = new Tale * [FIELD_LENGTH];

			for (int j = 0; j < FIELD_LENGTH; j++)
				tales[i][j] = new Tale(window, position + sf::Vector2f(23 + TALE_SIZE * j + TALE_SIZE / 2.f, 25 + TALE_SIZE * i + TALE_SIZE / 2.f), talesTexture, TaleType::NONE);
		}
	}
	~Field();

	void draw();
	void processMouseClick(sf::Vector2i mousePosition, TaleType baseActiveTale);
	bool checkWin();
	void reset();

private:
	bool checkTale(sf::Vector2i tale, Side enter);
};

