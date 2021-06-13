#pragma once
#include "Entity.h"
class Field : public Entity {
private:


public:
	Field(sf::RenderWindow* windowToLink, sf::Vector2f position, const sf::Texture& texture) 
		: Entity(windowToLink, position)
	{
		sprite.setTexture(texture);
	}

	void draw();
};

