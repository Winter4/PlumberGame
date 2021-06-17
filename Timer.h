#pragma once
#include <SFML/Graphics.hpp>

class Timer {
private:
	sf::RenderWindow* window;

	sf::Text text;

	sf::Clock timer;
	short time;
	bool over;

public:
	Timer(sf::RenderWindow* window, const sf::Font& font);

	void substractSecond();
	void reset();
	sf::Time getElapsedTime();
	void restart();
	short getTime();
	void draw();
	void end(const std::string& text);
	void end();
};
