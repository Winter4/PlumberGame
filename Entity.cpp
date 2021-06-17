#pragma once
#include "Entity.hpp"

// базовый абстрактный класс сущности
Entity::Entity(sf::RenderWindow* window)
{
	this->window = window;
}