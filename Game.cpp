#include "Game.h"

Game::Game() : window(sf::VideoMode(1400, 900), "PLUMBER")
{
	texturesHolder.load(Textures::Background, "assets/textures/background.png");
	texturesHolder.load(Textures::Field, "assets/textures/field.png");

	background.setTexture(texturesHolder.get(Textures::Background));
	field = new Field(&window, { 440, 15 }, texturesHolder.get(Textures::Field));
}

void Game::run()
{
	while (window.isOpen()) {
		processEvents();
		update();
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	window.pollEvent(event);

	switch (event.type) {
	case sf::Event::Closed:
		window.close();
		break;

	}
}

void Game::update()
{

}

void Game::render()
{
	window.clear();

	window.draw(background);
	field->draw();

	window.display();
}

Game::~Game()
{

}
