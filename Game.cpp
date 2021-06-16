#include "Game.h"

void Game::loadAssets()
{
	texturesHolder.load(Textures::Background, "assets/textures/background.png");
	texturesHolder.load(Textures::Field, "assets/textures/field.png");
	texturesHolder.load(Textures::Tales, "assets/textures/talesTest.png");
	texturesHolder.load(Textures::TalesBase, "assets/textures/talesBase.png");
	texturesHolder.load(Textures::Arrow, "assets/textures/arrow.png");

	fontsHolder.load(Fonts::Calibri, "assets/fonts/calibri.ttf");
}

Game::Game() : window(sf::VideoMode(1400, 900), "PLUMBER")
{
	loose = false;

	loadAssets();
	window.setFramerateLimit(60);
	baseActiveTale = TaleType::NONE;

	background.setTexture(texturesHolder.get(Textures::Background));
	entrance.setTexture(texturesHolder.get(Textures::Arrow));
	exit.setTexture(texturesHolder.get(Textures::Arrow));
	int enter = (FIELD_LENGTH - 1) * rand() / RAND_MAX + 1;
	int out = (FIELD_LENGTH - 1) * rand() / RAND_MAX + 1;
	entrance.setPosition(400, 15 + enter * TALE_SIZE - TALE_SIZE / 2.f);
	exit.setPosition(1315, 15 + out * TALE_SIZE - TALE_SIZE / 2.f);

	field = new Field(&window, { 440, 15 }, texturesHolder.get(Textures::Field), texturesHolder.get(Textures::Tales), enter, out);
	base = new TalesBase(&window, { 30, 500 }, texturesHolder.get(Textures::TalesBase), texturesHolder.get(Textures::Tales));
	timer = new Timer(&window, fontsHolder.get(Fonts::Calibri));
}

void Game::run()
{
	timer->restart();
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
	if (timer->getTime() <= 0) {
		if (field->checkWin()) timer->end("You loose :(");
		else timer->end("You win!");
		render();

		sf::Event event;
		while (true) {
			if (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed)
					window.close();

				if (event.type == sf::Event::KeyPressed)
					break;
			}
		}
		window.close();
	}

	if (timer->getElapsedTime() >= sf::seconds(1)) {
		timer->substractSecond();
		timer->restart();
	}

	base->highlightTale(baseActiveTale);
	std::cout << baseActiveTale;

	if (loose) {
		//system("pause");
		window.close();
	}
}

void Game::render()
{
	window.clear();

	window.draw(background);
	field->draw();
	base->draw();
	window.draw(entrance);
	window.draw(exit);
	timer->draw();

	window.display();
}

Game::~Game()
{
	delete field;
	delete base;
}
