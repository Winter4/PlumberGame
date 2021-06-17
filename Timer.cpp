#include "Timer.h"

// убрать секунду по счетчика
void Timer::substractSecond()
{
	time--;
}

// обнулить таймер
void Timer::reset()
{
	over = false;

	text.setPosition(sf::Vector2f(100, 200));
	text.setFillColor(sf::Color::Black);
	
	text.setCharacterSize(72);

	time = 60;
}

sf::Time Timer::getElapsedTime()
{
	return timer.getElapsedTime();
}

// перезапустить таймер (внутренний)
void Timer::restart()
{
	timer.restart();
}

short Timer::getTime()
{
	return time;
}

void Timer::draw()
{
	// устанавливаем текущее значение таймера
	if (!over) text.setString("     " + std::to_string(time) + "\nR to skip\nP/U to p/up");

	// красим
	if (time <= 10) text.setFillColor(sf::Color::Red);
	else text.setFillColor(sf::Color::Black);

	// рисуем
	FontedEntity::draw();
}

// надпись после конца игры
void Timer::end(const std::string& ending)
{
	text.setString(ending);
	over = true;
	text.move({ -50, 0 });
	text.setCharacterSize(40);
}

// скип таймера
void Timer::end()
{
	time = 1;
}

// пауза (ожидание нажатия U)
void Timer::pause()
{
	sf::Event event;

	while (window->isOpen()) {
		while (window->pollEvent(event)) {

			if (event.key.code == sf::Keyboard::U)
				return;

			if (event.type == event.Closed)
				window->close();
		}
	}
}