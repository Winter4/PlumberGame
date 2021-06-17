#pragma once
#include "TexturedEntity.hpp"
#include "TexturesID.h"

// размер спрайта (куска текстуры) в пикселях
#define TALE_SIZE 83

class Tale : public TexturedEntity {
private:
	// активный/неактивный тайл
	bool active;
	// наличие выходов
	// подробно в Tale::setTale()
	bool exits[2][2];
	// наличие воды в тайле
	bool watered;

public:
	Tale(sf::RenderWindow* window, sf::Vector2f position, const sf::Texture& texture, TaleType taleType)
		: TexturedEntity(window, position, texture)
	{
		watered = false;
		setTale(taleType);
	}

	// отрисовать тайл
	void draw();
	// содержит ли курсор мыши
	bool contains(sf::Vector2i mousePosition);
	// подсветить выбранным значением (Да/Нет)
	void highlight(bool state);
	// установить тип тайла 
	void setTale(TaleType tale);
	
	// повернуть тайл
	void rotate();
	// проверка соединения с указанной стороны
	bool connected(Side side);

	// геттер активности
	bool isActive();
	// геттер наличия воды
	bool isWatered();

	// налить воды
	void fill();
};

