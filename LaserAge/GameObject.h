#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

//// Базовый класс ///////
class GameObject
{
protected:
	
	
	// координаты объекта + его скорость и скорость по осям + размер по осям
	float x, y, dx, dy, speed;
	int spriteHeight, spriteWidth;
	// Переменная которая говорит о существовании объекта
	bool iAmAlive;
	int windowWidth, windowHeight;
	Texture texture;
	Sprite sprite;
	String name;	

public:
	//GameObject(String Name, float X, float Y, int W, int H, TxtureManager & tm);
	
	FloatRect getRect() const {	return FloatRect(x, y, spriteWidth, spriteHeight);	}
	Sprite getSprite() const {	return sprite;  }
	int getSpriteHeight() const { return spriteHeight; }
	int getSpriteWidth() const { return spriteWidth; }	
	GameObject(String Name, float X, float Y, int W, int H);
	void virtual update(float time) = 0;
	
	//float& getX(GameObject & p) const { return p.x; }
	float getX() const { return x; }
	//float& getY(GameObject & p) const{	return p.y; }
	float getY() const { return y; }
	String getName() const { return name; }

	~GameObject();
};

