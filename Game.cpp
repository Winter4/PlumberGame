#include "Game.h"

// загрузить ассеты (ресурсы)
void Game::loadAssets()
{
	// первый параметр - идентификатор, по которому будем обращаться к этому ресурсу
	texturesHolder.load(Textures::Background, "assets/textures/background.png");
	texturesHolder.load(Textures::Field, "assets/textures/field.png");
	texturesHolder.load(Textures::Tales, "assets/textures/talesTest.png");
	texturesHolder.load(Textures::TalesBase, "assets/textures/talesBase.png");
	texturesHolder.load(Textures::Arrow, "assets/textures/arrow.png");

	fontsHolder.load(Fonts::Calibri, "assets/fonts/calibri.ttf");
}

// конструктор
Game::Game() : window(sf::VideoMode(1400, 900), "PLUMBER")
{
	// загрузили ресурсы
	loadAssets();
	// максимум ФПС
	window.setFramerateLimit(60);
	// не выбрано никаких тайлов на базе
	baseActiveTale = TaleType::NONE;

	// устанавливаем текстуры для спрайтов
	background.setTexture(texturesHolder.get(Textures::Background));
	entrance.setTexture(texturesHolder.get(Textures::Arrow));
	exit.setTexture(texturesHolder.get(Textures::Arrow));

	// рандомим вход и выход
	int enter = (FIELD_LENGTH - 1) * rand() / RAND_MAX + 1;
	int out = (FIELD_LENGTH - 1) * rand() / RAND_MAX + 1;

	// ставим вход и выход
	entrance.setPosition(400, 15 + enter * TALE_SIZE - TALE_SIZE / 2.f);
	exit.setPosition(1315, 15 + out * TALE_SIZE - TALE_SIZE / 2.f);

	// создаём объекты
	field = new Field(&window, { 440, 15 }, texturesHolder.get(Textures::Field), texturesHolder.get(Textures::Tales), enter, out);
	base = new TalesBase(&window, { 30, 500 }, texturesHolder.get(Textures::TalesBase), texturesHolder.get(Textures::Tales));
	timer = new Timer(&window, { 100, 200 }, fontsHolder.get(Fonts::Calibri));
}

// запуск игры (вызывается в мейне)
void Game::run()
{
	timer->restart();
	while (window.isOpen()) {
		processEvents();
		update();
		render();
	}
}

// обработчик событий
void Game::processEvents()
{
	sf::Event event;
	// считали события
	window.pollEvent(event);

	// вывод позиции мыши (отладка)
	system("cls");
	std::cout << sf::Mouse::getPosition(window).x << "  " << sf::Mouse::getPosition(window).y << std::endl;

	switch (event.type) {
		// закрыть  окно
	case sf::Event::Closed:
		window.close();
		break;

		// нажатие клавиши на клавиатуре
	case sf::Event::KeyPressed:
		// скипнуть таймер
		if (event.key.code == sf::Keyboard::R)
			timer->end();

		// запаузить игру
		if (event.key.code == sf::Keyboard::P)
			timer->pause();

		break;

		// нажатие клавиши мыши
	case sf::Event::MouseButtonPressed:
		// ЛКМ
		if (event.key.code == sf::Mouse::Left) {
			field->processMouseClick(sf::Mouse::getPosition(window), baseActiveTale);
			
			baseActiveTale = TaleType::NONE;
			if (base->getRect().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) 
				baseActiveTale = base->processMouseClick(sf::Mouse::getPosition(window));
		}
		break;
	}
}

// обновить состояние игры
void Game::update()
{
	// кончился таймер (или его скипнули)
	if (timer->getTime() <= 0) {
		std::string text;
		text = field->checkWin() ? "You loose :(" : "You win!";
		text += "\nPress R to restart\nPress any key to exit";
		timer->end(text);
		render();

		// ждём нажатия клавиш
		sf::Event event;
		bool loop = true;
		while (loop) {
			window.pollEvent(event);
			switch (event.type) {
			case sf::Event::Closed:
				window.close();

			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::R)
					reset();
				else window.close();
				loop = false;
				break;
			}
		}
	}

	// если прошла секунда, уменьшить таймер на единичку
	if (timer->getElapsedTime() >= sf::seconds(1)) {
		timer->substractSecond();
		timer->restart();
	}

	// если выбрана плитка на базе, подсветить её
	base->highlightTale(baseActiveTale);
}

// отрисовать объекты
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

// обнулить игру
void Game::reset()
{
	field->reset();
	timer->reset();
}

Game::~Game()
{
	delete field;
	delete base;
}
