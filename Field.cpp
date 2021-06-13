#include "Field.h"

void Field::draw()
{
	Entity::draw();
	for (int i = 0; i < FIELD_LENGTH; i++)
		for (int j = 0; j < FIELD_LENGTH; j++)
			tales[i][j]->draw();
}

void Field::processMouseClick(sf::Vector2i mousePosition, TaleType activeTale)
{
	if (activeTale == TaleType::NONE) return;

	for (int i = 0; i < FIELD_LENGTH; i++)
		for (int j = 0; j < FIELD_LENGTH; j++)
			if (tales[i][j]->processMouseClick(mousePosition)) {
				tales[i][j]->setTale(activeTale);
				return;
			}
	return;
}