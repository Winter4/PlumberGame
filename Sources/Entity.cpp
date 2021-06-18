#pragma once
#include "../Headers/Entity.hpp"

// базовый абстрактный класс сущности
Entity::Entity(sf::RenderWindow* window)
{
	this->window = window;
}