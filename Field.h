#pragma once
#include "Entity.h"
class Field : public Entity {
private:


public:
	Field(sf::RenderWindow* window, sf::Vector2f position, const sf::Texture& texture) 
		: Entity(window, position, texture) {}

	void draw();
};

