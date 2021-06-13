#include "Field.h"

void Field::draw()
{
	Entity::draw();
	for (int i = 0; i < FIELD_LENGTH; i++)
		for (int j = 0; j < FIELD_LENGTH; j++)
			tales[i][j]->draw();
}

void Field::processMouseClick(sf::Vector2i mousePosition, TaleType baseActiveTale)
{
	for (int i = 0; i < FIELD_LENGTH; i++)
		for (int j = 0; j < FIELD_LENGTH; j++)
			if (tales[i][j]->contains(mousePosition)) {
				if (baseActiveTale != TaleType::NONE) {
					tales[i][j]->setTale(baseActiveTale);
					activeTale = { j, i };
				}
				else 
					tales[i][j]->rotate();

				return;
			}
}