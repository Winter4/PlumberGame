#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "ResourceHolder.hpp"
#include "TexturesID.h"

#include "Field.h"
#include "TalesBase.h"

class Game {
private:
	sf::RenderWindow window;
	ResourceHolder<sf::Texture, Textures::ID> texturesHolder;

	sf::Sprite background;
	Field* field;
	TalesBase* base;

	TaleType baseActiveTale;

public:
	Game();
	~Game();

	void run();

private:
	void loadAssets();

	void processEvents();
	void update();
	void render();
};

