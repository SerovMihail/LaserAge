#include "Player.h"
#include "IBullet.h"
#include "IGameObject.h"
//#include <list>
//#include <iterator>
//#include <vector>
#include <SFML/Graphics.hpp>

//// ������� ����� ///////
IGameObject::IGameObject(Image &image, String Name, float X, float Y, int W, int H)
{	// ������ ������ � ���� ����� �������� ����� �������. ��������, �� ������� ����� ������������ ��� ������� ���� ��
	// �������� � ������� ������ IGameObject 
	// ��������� �����������, ������� ������������ ����� �������
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setScale(0.5, 0.5); // �������


	//������ ���� ������� ����� ���� �������� 
	windowWidth = W; windowHeight = H;
	//������ ������ ����� ����� ���������� � ������, ������ �������
	x = X; y = Y; 
	spriteHeight = sprite.getTextureRect().height; // ������ �������
	spriteWidth = sprite.getTextureRect().width; // ������ �������	
	// � ��� �� ����� �������� � �������� �� �����������
	speed = 0; dx = 0; dy = 0;
	// ������ ������ ����������, ����� ��� ��������
	iAmAlive = true;
	
	
	
	name = Name; //��� �����

	sprite.setPosition(x, y);
}


void IGameObject::update(float time)
{

}



IGameObject::~IGameObject()
{
}


