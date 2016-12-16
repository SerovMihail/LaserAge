#include "NormalEnemy.h"
#include "Enemy.h"
#include "TextureManager.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list> 
#include <algorithm> 

using namespace sf;

NormalEnemy::NormalEnemy(String Name, float X, float Y, int W, int H) :Enyme(Name, X, Y, W, H) {
	x = X;
	y = Y;


	dx = 0.3;
	dy = 0.3;

	
	
	texture.loadFromImage(tm.getEnemyImg(2));
	sprite.setTexture(texture);
	sprite.setScale(0.5, 0.5); // масштаб

	spriteHeight = sprite.getTextureRect().height; // Высота спрайта
	spriteWidth = sprite.getTextureRect().width; // Ширина спрайта	
}
void NormalEnemy::dv(float time) {
	x = x + dx*time;
	y = y + dy*time;
	if (y >= 250 || y <= 50) {
		dy = dy*(-1);
	}
	if (x >= 900 || x <= 60) {
		//t1 = 0;
		dx = dx*(-1);
	}
	sprite.setPosition(x, y);
}


