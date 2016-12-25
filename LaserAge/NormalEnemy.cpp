#include "NormalEnemy.h"
#include "Enemy.h"
#include "TextureManager.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list> 
#include <algorithm> 

using namespace sf;

NormalEnemy::NormalEnemy(String Name, float X, float Y, int W, int H) :Enemy(Name, X, Y, W, H) {
	x = X;
	y = Y;


	dx = 0.2;
	dy = 0.3;

	
	
	texture.loadFromImage(tm.getEnemyImg(2));
	sprite.setTexture(texture);
	sprite.setScale(0.5, 0.5); // масштаб

	spriteHeight = sprite.getTextureRect().height; // Высота спрайта
	spriteWidth = sprite.getTextureRect().width; // Ширина спрайта	
}
void NormalEnemy::update(float time, int width, int heigth) {
	
	if (y >= heigth-280 || y <= (heigth-(heigth-30))) {
		dy = dy*(-1);
	}
	if (x >= (width-40) || x <=(width-(width- 40))) {
		
		dx = dx*(-1);
	}

	x = x + dx*time;
	y = y + dy*time;

	//while (x > 961)
	//{
	//	x = 959;

	//}

	//while (x < 35) {
	//	x = 39;
	//}

	//while (y > 225)
	//{
	//	y = 219;

	//}

	//while (y < 25) {
	//	y = 31;
	//}

	

	sprite.setPosition(x, y);
}


