#include "GameObject.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class TextureManager;
//// ������� ����� ///////
GameObject::GameObject(String Name, float X, float Y,  int W, int H, TextureManager & tm)
{	// ������ ������ � ���� ����� �������� ����� �������. ��������, �� ������� ����� ������������ ��� ������� ���� ��
	// �������� � ������� ������ IGameObject 
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
	//texture.loadFromImage(tm.getDefaultImg());
	//sprite.setTexture(texture);
	//sprite.setScale(0.5, 0.5); // �������
	//spriteHeight = sprite.getTextureRect().height; // ������ �������
	//spriteWidth = sprite.getTextureRect().width; // ������ �������	

	sprite.setPosition(x, y);
}


void GameObject::update(float time)
{
	
}



GameObject::~GameObject()
{
}


