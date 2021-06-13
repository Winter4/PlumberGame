#include "Entity.h"

Entity::Entity(sf::RenderWindow* windowToLink, sf::Vector2f position)
{
	window = windowToLink;
	sprite.setPosition(position);
}

void Entity::draw()
{
	window->draw(sprite);
}
