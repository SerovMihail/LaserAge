#pragma once
#include <SFML/Graphics.hpp>
//#include "TextureManager.h"


using namespace sf;

class TextureManager;
//// ������� ����� ///////
class GameObject
{
protected:
	
	
	// ���������� ������� + ��� �������� � �������� �� ���� + ������ �� ����
	float x, y, dx, dy, speed;
	int spriteHeight, spriteWidth;
	// ���������� ������� ������� � ������������� �������
	bool iAmAlive;
	int windowWidth, windowHeight;
	Texture texture;
	Sprite sprite;
	String name;	

public:
	GameObject(String Name, float X, float Y, int W, int H, TextureManager & tm);
	
	FloatRect getRect() const {	return FloatRect(x, y, spriteWidth, spriteHeight);	}
	Sprite getSprite() const {	return sprite;  }
	int getSpriteHeight() const { return spriteHeight; }
	int getSpriteWidth() const { return spriteWidth; }	
	void update(float time);
	//float& getX(GameObject & p) const { return p.x; }
	float getX() const { return x; }
	//float& getY(GameObject & p) const{	return p.y; }
	float getY() const { return y; }
	String getName() const { return name; }

	~GameObject();
};

