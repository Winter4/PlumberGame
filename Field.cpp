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
	if (activeTale.x != -1) 
		tales[activeTale.y][activeTale.x]->highlight(false);

	for (int i = 0; i < FIELD_LENGTH; i++)
		for (int j = 0; j < FIELD_LENGTH; j++)
			if (tales[i][j]->contains(mousePosition)) {
				if (baseActiveTale != TaleType::NONE) {
					tales[i][j]->setTale(baseActiveTale);
					activeTale = { j, i };
				}
				else 
					if (tales[i][j]->isActive()) 
						tales[i][j]->highlight(true);
				
				return;
			}
}