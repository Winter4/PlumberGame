#include "Game.h"

void Game::loadAssets()
{
	texturesHolder.load(Textures::Background, "assets/textures/background.png");
	texturesHolder.load(Textures::Field, "assets/textures/field.png");
	texturesHolder.load(Textures::Tales, "assets/textures/talesTest.png");
	texturesHolder.load(Textures::TalesBase, "assets/textures/talesBase.png");
	texturesHolder.load(Textures::Arrow, "assets/textures/arrow.png");
}

Game::Game() : window(sf::VideoMode(1400, 900), "PLUMBER")
{
	gameOver = false;

	loadAssets();
	window.setFramerateLimit(60);
	baseActiveTale = TaleType::NONE;

	background.setTexture(texturesHolder.get(Textures::Background));
	entrance.setTexture(texturesHolder.get(Textures::Arrow));
	enter = (FIELD_LENGTH - 1) * rand() / RAND_MAX + 1;
	entrance.setPosition(400, 15 + enter * TALE_SIZE - TALE_SIZE / 2.f);

	field = new Field(&window, { 440, 15 }, texturesHolder.get(Textures::Field), texturesHolder.get(Textures::Tales));
	base = new TalesBase(&window, { 30, 500 }, texturesHolder.get(Textures::TalesBase), texturesHolder.get(Textures::Tales));
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

	system("cls");
	std::cout << sf::Mouse::getPosition(window).x << "  " << sf::Mouse::getPosition(window).y << std::endl;

	switch (event.type) {
	case sf::Event::Closed:
		window.close();
		break;

	case sf::Event::KeyPressed:
		if (event.key.code == sf::Keyboard::Enter)
			gameOver = field->flowWater(enter);
		break;

	case sf::Event::MouseButtonPressed:
		if (event.key.code == sf::Mouse::Left) {
			field->processMouseClick(sf::Mouse::getPosition(window), baseActiveTale);
			
			baseActiveTale = TaleType::NONE;
			if (base->getRect().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) 
				baseActiveTale = base->processMouseClick(sf::Mouse::getPosition(window));
		}
		break;
	}
}

void Game::update()
{
	base->highlightTale(baseActiveTale);
	std::cout << baseActiveTale;

	if (gameOver) window.close();
}

void Game::render()
{
	window.clear();

	window.draw(background);
	field->draw();
	base->draw();
	window.draw(entrance);

	window.display();
}

Game::~Game()
{

}
