#pragma once
#include "TexturedEntity.hpp"
#include "Tale.h"
#include "TexturesID.h"
#include <iostream>

// длина поля (в клетках)
#define FIELD_LENGTH 10

// Игровое поле
class Field : public TexturedEntity {
private:
	// матрица клеток
	Tale*** tales;
	// позиция текущей выбранной клетки
	sf::Vector2i activeTale;
	// вход воды
	int waterEnter;
	// выход воды
	int waterExit;

public:
	Field(sf::RenderWindow* window, sf::Vector2f position, const sf::Texture& texture, const sf::Texture& talesTexture, int enterToSet, int exitToSet)
		: TexturedEntity(window, position, texture)
	{
		activeTale = { -1, -1 };
		waterEnter = enterToSet;
		waterExit = exitToSet;

		// создаём пустые клетки
		tales = new Tale * *[FIELD_LENGTH];
		for (int i = 0; i < FIELD_LENGTH; i++) {
			tales[i] = new Tale * [FIELD_LENGTH];

			for (int j = 0; j < FIELD_LENGTH; j++)
				// 23, 25 - ширины границ спрайта поля
				tales[i][j] = new Tale(window, position + sf::Vector2f(23 + TALE_SIZE * j + TALE_SIZE / 2.f, 25 + TALE_SIZE * i + TALE_SIZE / 2.f), talesTexture, TaleType::NONE);
		}
	}
	~Field();

	// отрисовать поле и поставленные трубы
	void draw();
	// если была нажата ЛКМ внутри поля
	void processMouseClick(sf::Vector2i mousePosition, TaleType baseActiveTale);
	// итог игры (В-П)
	bool checkWin();
	// обнуление поля
	void reset();

private:
	// проверка трубы на обрыв (часть checkWin(), основная проверяющая функция)
	bool checkTale(sf::Vector2i tale, Side enter);
};

