#include "TalesBase.h"

void TalesBase::draw()
{
	Entity::draw();
	for (int i = 0; i < TALES_NUMBER; i++)
		tales[i]->draw();
}

sf::FloatRect TalesBase::getRect() { return sprite.getGlobalBounds(); }

TaleType TalesBase::processMouseClick(sf::Vector2i mousePosition)
{
	if (activeTale != TaleType::NONE) tales[activeTale - 1]->highlight(false);

	for (int i = 0; i < TALES_NUMBER; i++)
		if (tales[i]->contains(mousePosition)) 
			activeTale = TaleType(i + 1);
	
	return activeTale;
}

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