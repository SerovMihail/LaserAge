#pragma once
#include <SFML/Graphics.hpp>
#include <iostream> 
#include <sstream>

using namespace sf;


//// ������� ����� ///////
class IGameObject
{
protected:
	//std::vector<IBullet> bullets;
	//������ ����
	
	// ���������� ������� + ��� �������� � �������� �� ���� + ������ �� ����
	float x, y, dx, dy, speed;
	int spriteHeight, spriteWidth;
	// ���������� ������� ������� � ������������� �������
	bool iAmAlive;

	Texture texture;
	Sprite sprite;
	String name;	

public:
	int windowWidth, windowHeight;

	IGameObject(Image &image, String Name, float X, float Y, int W, int H);
	FloatRect getRect() const {	return FloatRect(x, y, spriteWidth, spriteHeight);	}
	Sprite getSprite() const {	return sprite;  }
	int getSpriteHeight() const { return spriteHeight; }
	int getSpriteWidth() const { return spriteWidth; }
	void update(float time);	
	virtual float& getX(IGameObject & p) const { return p.x; }
	virtual float& getY(IGameObject & p) const{	return p.y; }
	String getName() const { return name; }

	~IGameObject();
};

