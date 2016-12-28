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

	windowHeight = H;
	windowWidth = W;


	dx = 0.2;
	dy = 0.3;

	
	
	texture.loadFromImage(tm.getEnemyImg(2));
	sprite.setTexture(texture);
	sprite.setScale(0.5, 0.5); // �������

	spriteHeight = sprite.getTextureRect().height; // ������ �������
	spriteWidth = sprite.getTextureRect().width; // ������ �������	
}
void NormalEnemy::update(float time) {
	
	if (y >= windowHeight -280 || y <= (windowHeight -(windowHeight -30))) {
		dy = dy*(-1);
	}
	if (x >= (windowWidth -40) || x <=(windowWidth -(windowWidth- 40))) {
		
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


