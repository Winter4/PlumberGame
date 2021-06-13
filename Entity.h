#pragma once
#include <SFML/Graphics.hpp>

class Entity {
protected:
	sf::RenderWindow* window;
	sf::Sprite sprite;

public:
	Entity(sf::RenderWindow* windowToLink, sf::Vector2f position);

	void draw();
};

