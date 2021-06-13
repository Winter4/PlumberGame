#pragma once
#include "Entity.h"
#include "TexturesID.h"

#define TALE_SIZE 83

class Tale : public Entity {
private:
	bool active;

public:
	Tale(sf::RenderWindow* window, sf::Vector2f position, const sf::Texture& texture, TaleType taleType)
		: Entity(window, position, texture)
	{
		setTale(taleType);
	}

	void draw();
	bool contains(sf::Vector2i mousePosition);
	void highlight(bool state);
	void setTale(TaleType tale);
	bool isActive();
};

