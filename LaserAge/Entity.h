#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TextureManager.h"
#include <list> 
#include <algorithm> 

using namespace sf;
using namespace std;

class TextureManager;
class Entity {
private:
	float x, y, dx, dy, t1, time, x1, y1, x2, y2, dx1, dx2, moveTimer;
	int health, speed;
	bool life;
	int spriteHeight, spriteWidth;
	string name;
	Texture texture;
	Sprite sprite;
public:
	//Entity(Image &image, float X, float Y, int HEALTH);
	Entity(TextureManager & tm, float X, float Y, int HEALTH);
	void update(float time);
	//FloatRect getRect() const { return FloatRect(x, y, spriteWidth, spriteHeight); }
};

