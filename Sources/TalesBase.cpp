#include "../Headers/TalesBase.h"

void TalesBase::draw()
{
	TexturedEntity::draw();
	for (int i = 0; i < TALES_NUMBER; i++)
		tales[i]->draw();
}

sf::FloatRect TalesBase::getRect() { return sprite.getGlobalBounds(); }

// обработчик клика мыши по базе
TaleType TalesBase::processMouseClick(sf::Vector2i mousePosition)
{
	// убрать подсветку
	if (activeTale != TaleType::NONE) tales[activeTale - 1]->highlight(false);

	// проверить, кликнули ли по клетке
	for (int i = 0; i < TALES_NUMBER; i++)
		// если да, подсветить её
		if (tales[i]->contains(mousePosition)) 
			activeTale = TaleType(i + 1);
	
	// вернуть подсвеченную (или нет) клетку
	return activeTale;
}

// подсветить клетку базы
void TalesBase::highlightTale(TaleType tale)
{
	if (tale != TaleType::NONE) {
		tales[activeTale - 1]->highlight(false);
		tales[tale - 1]->highlight(true);
	}
	else 
		if (activeTale != TaleType::NONE) tales[activeTale-1]->highlight(false);

	activeTale = tale;
}