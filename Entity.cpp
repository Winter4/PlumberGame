#include "Entity.h"

Entity::Entity(sf::RenderWindow* window, sf::Vector2f position, const sf::Texture& texture)
{
	this->window = window;
	sprite.setPosition(position);
	sprite.setTexture(texture);
}

void Entity::draw()
{
	window->draw(sprite);
}
