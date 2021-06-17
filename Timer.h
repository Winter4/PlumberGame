#pragma once
#include <SFML/Graphics.hpp>
#include "FontedEntity.hpp"

// ����� ������
class Timer : FontedEntity {
private:
	// ���������� ������, ������� ����� ����� �������
	sf::Clock timer;
	// ������� ������� �������
	short time;
	// ���� �������� ?
	bool over;

public:
	Timer(sf::RenderWindow* window, sf::Vector2f position, const sf::Font& font)
		: FontedEntity(window, position, font)
	{
		// ���������� ������ � ������
		reset();
	}

	// ��������� �� �������
	void substractSecond();
	// �������� ������
	void reset();
	// ������ ���������� ������� ����������� �������
	sf::Time getElapsedTime();
	// �������� ���������� ������
	void restart();
	// ������ �������� �������
	short getTime();
	// ��������� ������
	void draw();
	// ����� ���� (��������� ������)
	void end(const std::string& text);
	// ����� ���� (���� �������)
	void end();
	// �����
	void pause();
};
