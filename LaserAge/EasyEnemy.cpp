#include "EasyEnemy.h"
#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list> 
#include <algorithm> 
#include "TextureManager.h"


EasyEnemy::EasyEnemy(String Name, float X, float Y, int W, int H):Enyme(Name, X, Y, W, H)
{
	x = X;
	y = Y;
	dx = 0.07;	
		
	texture.loadFromImage(tm.getEnemyImg(1));
	sprite.setTexture(texture);
	sprite.setScale(0.5, 0.5);

	spriteHeight = sprite.getTextureRect().height; // ������ �������
	spriteWidth = sprite.getTextureRect().width; // ������ �������	
	
}
void EasyEnemy::dv(float time) {

	

	if (x > 860 || x < 40) {
		
		dx = dx*(-1);
	}

	x = x + dx*time;


	while (x > 865 )
	{
		//x = x - dx*time;	
		x = 859;
	}

	while (x < 35) {
		//x = x + dx*time;
		x = 41;
	}
	

	sprite.setPosition(x, y);
}


