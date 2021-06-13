#pragma once
#include <SFML/Graphics.hpp>
#include "ResourceHolder.hpp"
#include "TexturesID.h"

#include "Field.h"

class Game {
private:
	sf::RenderWindow window;
	ResourceHolder<sf::Texture, Textures::ID> texturesHolder;

	sf::Sprite background;
	Field* field;

public:
	Game();
	~Game();

	void run();

private:
	void processEvents();
	void update();
	void render();
};

