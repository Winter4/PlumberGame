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

bool Field::flowWater(int enter)
{
	bool win = false;
	sf::Vector2i curTale(enter - 1, 0);
	Side cameFrom = Side::Left;

	while (win == false) {
		// перебор выходов
		for (int i = cameFrom + 1; i != cameFrom; i++) {
			if (i > 3) i = 0;

			// определяем текущий выход
			sf::Vector2i exit;
			switch (i) {
			case 0:
				exit = { 0, 0 };
				break;

			case 1:
				exit = { 0, 1 };
				break;

			case 2:
				exit = { 1, 1 };
				break;

			case 3:
				exit = { 1, 0 };
				break;
			}

			// соединён ли выход с чем-то
			//if (curTaleexits[exit.x][exit[y]])
		}
	}

	return false;
}