#include "EasyEnemy.h"
#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameManager.h"
#include <algorithm> 
#include "TextureManager.h"
#include "Bullet.h"

EasyEnemy::EasyEnemy(String Name, float X, float Y, int W, int H): Enemy(Name, X, Y, W, H)
{
	x = X;
	y = Y;
	dx = 0.1;	


	windowHeight = H;
	windowWidth = W;

		
	//texture.loadFromImage(tm.getEnemyImg(1));
	sprite.setTexture(*tm.get("enemy1"));
	sprite.setScale(0.5, 0.5);

	spriteHeight = sprite.getTextureRect().height; // Высота спрайта
	spriteWidth = sprite.getTextureRect().width; // Ширина спрайта	

	
}

void EasyEnemy::update(float time) {

	x = x + dx*time;

	if (x > (windowWidth - 140) || x < (windowWidth - (windowWidth - 40))) {

		dx = dx*(-1);
	}
	
	while (x > (windowWidth - 130))
	{
		x = windowWidth - 160;
	}

	while (x < (windowWidth - (windowWidth - 20))) {
		x = (windowWidth - (windowWidth - 50));
	}
	

	//while (x > 865 )
	//{
	//	//x = x - dx*time;	
	//	x = 859;
	//}

	//while (x < 35) {
	//	//x = x + dx*time;
	//	x = 41;
	//}


	sprite.setPosition(x, y);
}


