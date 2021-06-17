#pragma once
#include "Entity.hpp"

// сущность со спрайтом
class TexturedEntity : public Entity {
protected:
	sf::Sprite sprite;

public:
	TexturedEntity(sf::RenderWindow* window, sf::Vector2f position, const sf::Texture& texture);

	void virtual draw();
};

