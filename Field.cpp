#include "Field.h"

// отрисовать спрайт поля и все поставленные трубы
void Field::draw()
{
	TexturedEntity::draw();
	for (int i = 0; i < FIELD_LENGTH; i++)
		for (int j = 0; j < FIELD_LENGTH; j++)
			tales[i][j]->draw();
}

// обработчик нажатия мыши внутри поля
void Field::processMouseClick(sf::Vector2i mousePosition, TaleType baseActiveTale)
{
	// была ли нажата клетка
	for (int i = 0; i < FIELD_LENGTH; i++)
		for (int j = 0; j < FIELD_LENGTH; j++)
			// если была
			if (tales[i][j]->contains(mousePosition)) {
				// если на базе выбран тайл
				if (baseActiveTale != TaleType::NONE) {
					// поставить на поле
					tales[i][j]->setTale(baseActiveTale);
					activeTale = { j, i };
				}
				else 
					// иначе повернуть тайл
					tales[i][j]->rotate();

				return;
			}
}

// узнать результаты игры
bool Field::checkWin()
{
	// наличие соединения на выходе (справа)
	if (!(tales[waterExit - 1][FIELD_LENGTH - 1])->connected(Side::Right)) return true;
	
	// запуск рекурсивной функции
	// если вернёт TRUE, значит проигрыш
	if (checkTale({ 0, waterEnter - 1 }, Side::Left)) return true;

	// если FALSE, победа
	return false;
}

// рекурсивная функция - проверяет тайл и все его выходы
bool Field::checkTale(sf::Vector2i tale, Side enterSide)
{
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
		// после низа идёт лево (enum) 
		i = i > 3 ? 0 : i;

		// если дошли туда, откуда пришли, значит тут всё
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
			// выход след. клетки = выход этой + 2
			Side inSide = Side(i + 2 > 3 ? (i + 2) % 4 : i + 2);
			// если вернётся TRUE, значит по одному из критериев определено поражение
			if (checkTale(newTale, inSide)) return true;
		}
	}

	return false;
}

// обнулить игру (для новой игры)
void Field::reset()
{
	for (int i = 0; i < FIELD_LENGTH; i++)
		for (int j = 0; j < FIELD_LENGTH; j++)
			// заменить активные тайлы на пустые
			if (tales[i][j]->isActive()) tales[i][j]->setTale(TaleType::NONE);
}

// деструктор
Field::~Field()
{
	for (int i = 0; i < FIELD_LENGTH; i++) {
		for (int j = 0; j < FIELD_LENGTH; j++)
			delete tales[i][j];
		delete tales[i];
	}
	delete tales;
}

