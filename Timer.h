#pragma once
#include <SFML/Graphics.hpp>
#include "FontedEntity.hpp"

// Класс таймер
class Timer : FontedEntity {
private:
	// внутренний таймер, считает время между кадрами
	sf::Clock timer;
	// текущее значени времени
	short time;
	// игра окончена ?
	bool over;

public:
	Timer(sf::RenderWindow* window, sf::Vector2f position, const sf::Font& font)
		: FontedEntity(window, position, font)
	{
		// сбрасываем таймер в начале
		reset();
	}

	// уменьшить на секунду
	void substractSecond();
	// сбросить таймер
	void reset();
	// геттер прошедшего времени внутреннего таймера
	sf::Time getElapsedTime();
	// сбросить внутренний таймер
	void restart();
	// геттер текущего времени
	short getTime();
	// отрисвать таймер
	void draw();
	// конец игры (установка текста)
	void end(const std::string& text);
	// конец игры (скип таймера)
	void end();
	// пауза
	void pause();
};
