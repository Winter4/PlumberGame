#pragma once
#include <SFML/Graphics.hpp>

class Entity {
protected:
	sf::RenderWindow* window;
	sf::Sprite sprite;

public:
	Entity(sf::RenderWindow* window, sf::Vector2f position, const sf::Texture& texture);

	void virtual draw();
};