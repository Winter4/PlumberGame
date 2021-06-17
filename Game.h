#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "ResourceHolder.hpp"
#include "TexturesID.h"

#include "Field.h"
#include "TalesBase.h"
#include "Timer.h"

class Game {
private:
	sf::RenderWindow window;
	ResourceHolder<sf::Texture, Textures::ID> texturesHolder;
	ResourceHolder<sf::Font, Fonts::ID> fontsHolder;


	sf::Sprite background;
	Field* field;
	TalesBase* base;
	Timer* timer;

	sf::Sprite entrance;
	sf::Sprite exit;

	TaleType baseActiveTale;
	bool loose;

public:
	Game();
	~Game();

	void run();

private:
	void loadAssets();

	void processEvents();
	void update();
	void render();

	void reset();
};

