#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "ResourceHolder.hpp"
#include "TexturesID.h"

#include "Field.h"
#include "TalesBase.h"
#include "Timer.h"

// класс игра
class Game {
private:
	// окно, в котором всё рисуется
	sf::RenderWindow window;

	// хранитель текстур
	ResourceHolder<sf::Texture, Textures::ID> texturesHolder;
	// хранитель щрифтов
	ResourceHolder<sf::Font, Fonts::ID> fontsHolder;

	// задник
	sf::Sprite background;
	// поле
	Field* field;
	// база труб
	TalesBase* base;
	// таймер с текстом
	Timer* timer;

	// стрелочки на вход и выход
	sf::Sprite entrance;
	sf::Sprite exit;

	// текущая выбранная клетка на базе
	TaleType baseActiveTale;

public:
	Game();
	~Game();

	// запуск (вызывается в мейне)
	void run();

private:
	// загрузить ресурсы (ассеты)
	void loadAssets();

	// обработчик событий
	void processEvents();
	// обновление состояния игры
	void update();
	// отрисовка объектов
	void render();

	// обнуление игры
	void reset();
};

