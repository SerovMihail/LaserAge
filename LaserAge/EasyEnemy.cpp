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
		
	texture.loadFromImage(tm.getEnemyImg(1));
	sprite.setTexture(texture);
	sprite.setScale(0.5, 0.5);

	spriteHeight = sprite.getTextureRect().height; // Высота спрайта
	spriteWidth = sprite.getTextureRect().width; // Ширина спрайта	

	
}
void EasyEnemy::update(int time, int width, int heigth) {

	
	x = x + dx*time;
	if (x >= (width-140) || x <= (width-(width-40))) {
		
		dx = dx*(-1);
	}
	while (x > (width - 130))
		{
			
			x = width - 160;
		}

		while (x < (width - (width - 20))) {
		
			x = (width - (width - 50));
		}
	
	
	

	sprite.setPosition(x, y);
}


