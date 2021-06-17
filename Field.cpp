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

bool Field::checkWin()
{
	// наличие соединения на выходе
	if (!(tales[waterExit - 1][FIELD_LENGTH - 1])->connected(Side::Right)) return true;
	
	if (checkTale({ 0, waterEnter - 1 }, Side::Left)) return true;
	return false;
}

bool Field::checkTale(sf::Vector2i tale, Side enterSide)
{
	//system("cls");
	//std::cout << tale.x << "  " << tale.y << "   " << enterSide;
	// проверка на выход за границы поля
	if (tale.x < 0 || tale.x > 9 || tale.y < 0 || tale.y > 9)
		// проверка на вход-выход (граница или В-В)
		if (tale.x == 10 && tale.y == waterExit - 1)
			return false;
		else return true;

	// проверка на наличие трубы
	if (!(tales[tale.y][tale.x]->isActive())) return true;

	// проверка на наличие воды
	if (tales[tale.y][tale.x]->isWatered()) return false;
	else 
		tales[tale.y][tale.x]->fill();

	// проверка на соед. с пред. трубой
	if (!(tales[tale.y][tale.x]->connected(enterSide))) return true;
	
	// проверяем остальные стороны на наличие выхода
	for (int i = enterSide + 1; ; i++) {
		// после низа идёт лево
		i = i > 3 ? 0 : i;
		if (i == enterSide) break;

		// если есть выход с этой стороны
		if (tales[tale.y][tale.x]->connected(Side(i))) {
			sf::Vector2i newTale(tale);
			// определяем координаты плитки, куда будем переходить
			switch (i) {
			case 0:
				newTale.x--;
				break;

			case 1:
				newTale.y--;
				break;

			case 2:
				newTale.x++;
				break;

			case 3:
				newTale.y++;
				break;
			}
			Side inSide = Side(i + 2 > 3 ? (i + 2) % 4 : i + 2);
			// если вернётся TRUE, значит по одному из критериев определено поражение
			if (checkTale(newTale, inSide)) return true;
		}
	}

	return false;
}

void Field::reset()
{
	for (int i = 0; i < FIELD_LENGTH; i++)
		for (int j = 0; j < FIELD_LENGTH; j++)
			if (tales[i][j]->isActive()) tales[i][j]->setTale(TaleType::NONE);
}

Field::~Field()
{
	for (int i = 0; i < FIELD_LENGTH; i++) {
		for (int j = 0; j < FIELD_LENGTH; j++)
			delete tales[i][j];
		delete tales[i];
	}
	delete tales;
}

