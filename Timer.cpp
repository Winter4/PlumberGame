#include "Timer.h"

Timer::Timer(sf::RenderWindow* window, const sf::Font& font)
{
	this->window = window;
	over = false;

	text.setPosition(sf::Vector2f(170, 200));
	text.setFillColor(sf::Color::Black);
	text.setFont(font);
	text.setCharacterSize(72);

	time = 60;
}

void Timer::substractSecond()
{
	time--;
}

void Timer::refresh()
{
	time = 60;
}

sf::Time Timer::getElapsedTime()
{
	return timer.getElapsedTime();
}

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
	if (!over) text.setString(std::to_string(time));

	if (time <= 10) text.setFillColor(sf::Color::Red);
	else text.setFillColor(sf::Color::Black);
	window->draw(text);
}

void Timer::end(const std::string& ending)
{
	text.setString(ending);
	over = true;
	text.move({ -100, 0 });
}