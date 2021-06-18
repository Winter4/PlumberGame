#include "../Headers/Tale.h"

void Tale::draw()
{
	if (active) TexturedEntity::draw();
}

// содержит ли клеточка курсор
bool Tale::contains(sf::Vector2i mousePosition)
{
	return sprite.getGlobalBounds().contains(sf::Vector2f(mousePosition));
}

// подсветить клетку
void Tale::highlight(bool state)
{
	if (state) sprite.setColor(sf::Color::Green);
	else sprite.setColor(sf::Color::White);
}

// поставить трубу
// exits - наличие выходов
void Tale::setTale(TaleType tale)
{
	active = true;
	switch (tale) {
	case TaleType::NONE:
		active = false;
		watered = false;

		exits[0][0] = 0; // лево
		exits[0][1] = 0; // верх
		exits[1][0] = 0; // низ
		exits[1][1] = 0; // право

		// выбираем для спрайта прямоугольный кусор текстуры с координатами ЛВ угла (0; 0)
		// и шириной и высотой TALE_SIZE
		// для TaleType::NONE не важен какой именно квадрат, важен размер, чтобы правильно обработать
		// нажатие мыши по пустой клетке
		sprite.setTextureRect(sf::IntRect(0, 0, TALE_SIZE, TALE_SIZE));
		break;

	case TaleType::Straight:
		sprite.setTextureRect(sf::IntRect(0, 0, TALE_SIZE, TALE_SIZE));
		exits[0][0] = 1;
		exits[0][1] = 0;
		exits[1][0] = 0;
		exits[1][1] = 1;
		break;

	case TaleType::Angle:
		sprite.setTextureRect(sf::IntRect(TALE_SIZE, 0, TALE_SIZE, TALE_SIZE));
		exits[0][0] = 1;
		exits[0][1] = 1;
		exits[1][0] = 0;
		exits[1][1] = 0;
		break;

	case TaleType::X:
		sprite.setTextureRect(sf::IntRect(TALE_SIZE * 2, 0, TALE_SIZE, TALE_SIZE));
		exits[0][0] = 1;
		exits[0][1] = 1;
		exits[1][0] = 1;
		exits[1][1] = 1;
		break;

	case TaleType::T:
		sprite.setTextureRect(sf::IntRect(TALE_SIZE * 3, 0, TALE_SIZE, TALE_SIZE));
		exits[0][0] = 1;
		exits[0][1] = 0;
		exits[1][0] = 1;
		exits[1][1] = 1;
		break;
	}

	// ставим центр в центр 
	sf::FloatRect rect = sprite.getLocalBounds();
	sprite.setOrigin(rect.left + rect.width / 2.f, rect.top + rect.height / 2.f);
	rect = sprite.getLocalBounds();

	// убираем вращения
	sprite.setRotation(0);
}

bool Tale::isActive() { return active; }

// повернуть на 90 градусов
void Tale::rotate()
{
	sprite.rotate(90.f);

	int tmp;
	tmp = exits[0][0];

	exits[0][0] = exits[1][0];
	exits[1][0] = exits[1][1];
	exits[1][1] = exits[0][1];
	exits[0][1] = tmp;
}

// проверяет, есть ли выход с указанной стороны
bool Tale::connected(Side side)
{
	bool result = false;

	switch (side) {
	case Side::Left:
		if (exits[0][0]) result = true;
		break;

	case Side::Top:
		if (exits[0][1]) result = true;
		break;

	case Side::Right:
		if (exits[1][1]) result = true;
		break;

	case Side::Bot:
		if (exits[1][0]) result = true;
		break;
	}

	return result;
}

bool Tale::isWatered() { return watered; }

// налить водички
void Tale::fill() { 
	watered = true; 
	sprite.setColor(sf::Color::Blue);
}