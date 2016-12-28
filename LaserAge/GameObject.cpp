#include "GameObject.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class TxtureManager;
//// ������� ����� ///////
GameObject::GameObject(String Name, float X, float Y,  int W, int H)
{	// ������ ������ � ���� ����� �������� ����� �������. ��������, �� ������� ����� ������������ ��� ������� ���� ��
	// �������� � ������� ������ GameObject 
	// ��������� �����������, ������� ������������ ����� �������

	//������ ���� ������� ����� ���� �������� 
	windowWidth = W; windowHeight = H;

	//������ ������ ����� ����� ���������� � ������, ������ �������
	x = X; y = Y; 
	
	// � ��� �� ����� �������� � �������� �� �����������
	speed = 0; dx = 0; dy = 0;

	// ������ ������ ����������, ����� ��� ��������
	iAmAlive = true;
	name = Name; 

	// ��� � ����������� �������
	//txture.loadFromImage(tm.di);
	//sprite.setTxture(txture);
	//sprite.setScale(0.5, 0.5); // �������

	//spriteHeight = sprite.getTxtureRect().height; // ������ �������
	//spriteWidth = sprite.getTxtureRect().width; // ������ �������	

	sprite.setPosition(x, y);
}


void GameObject::update(float time)
{
	
}



GameObject::~GameObject()
{
}


