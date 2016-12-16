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


	dx = 0.1;
	
		
	texture.loadFromImage(tm.getEnemyImg(1));
	sprite.setTexture(texture);
	sprite.setScale(0.5, 0.5);

	spriteHeight = sprite.getTextureRect().height; // Высота спрайта
	spriteWidth = sprite.getTextureRect().width; // Ширина спрайта	
	/*t.loadFromImage(image);
	s.setTexture(t);
	s.setScale(0.7, 0.7);
	s.setPosition(x, y);*/
}
void EasyEnemy::dv(float time) {


	x = x + dx*time;

	if (x >= 900 || x <= 60) {
		dx = dx*(-1);
	}
	sprite.setPosition(x, y);
}


