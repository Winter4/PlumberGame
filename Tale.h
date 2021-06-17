#pragma once
#include "TexturedEntity.hpp"
#include "TexturesID.h"

// ������ ������� (����� ��������) � ��������
#define TALE_SIZE 83

class Tale : public TexturedEntity {
private:
	// ��������/���������� ����
	bool active;
	// ������� �������
	// �������� � Tale::setTale()
	bool exits[2][2];
	// ������� ���� � �����
	bool watered;

public:
	Tale(sf::RenderWindow* window, sf::Vector2f position, const sf::Texture& texture, TaleType taleType)
		: TexturedEntity(window, position, texture)
	{
		watered = false;
		setTale(taleType);
	}

	// ���������� ����
	void draw();
	// �������� �� ������ ����
	bool contains(sf::Vector2i mousePosition);
	// ���������� ��������� ��������� (��/���)
	void highlight(bool state);
	// ���������� ��� ����� 
	void setTale(TaleType tale);
	
	// ��������� ����
	void rotate();
	// �������� ���������� � ��������� �������
	bool connected(Side side);

	// ������ ����������
	bool isActive();
	// ������ ������� ����
	bool isWatered();

	// ������ ����
	void fill();
};

