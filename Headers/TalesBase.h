#pragma once
#include "TexturedEntity.hpp"
#include "Tale.h"

// кол-во тайлов на базе
#define TALES_NUMBER 4

// Класс база для тайлов
class TalesBase : public TexturedEntity {
private:
	// тайлы в базе
	Tale** tales;
	// текущий выбранный тайл
	TaleType activeTale;

public:
	TalesBase(sf::RenderWindow* window, sf::Vector2f position, const sf::Texture& texture, const sf::Texture& talesTexture)
		: TexturedEntity(window, position, texture)
	{
		// текущий активный - никакой
		activeTale = TaleType::NONE;

		// память под тайлы
		tales = new Tale * [TALES_NUMBER];

		// каждого тайла по разу
		for (int i = 0; i < TALES_NUMBER; i++)
			tales[i] = new Tale(window, this->sprite.getPosition() + sf::Vector2f(23 + TALE_SIZE * i + TALE_SIZE / 2.f, 24 + TALE_SIZE / 2.f), talesTexture, TaleType(i + 1));
	}

	// отрисовать базу
	void draw();
	// геттер области
	sf::FloatRect getRect();
	// если был клик внутри базы
	TaleType processMouseClick(sf::Vector2i mousePosition);
	// подсветить тайл в базе
	void highlightTale(TaleType tale);
};

