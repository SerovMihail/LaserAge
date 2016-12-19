#include "HardEnemy.h"
#include <SFML/Graphics.hpp>
#include "TextureManager.h"

HardEnemy::HardEnemy(String Name, float X, float Y, int W, int H) :Enyme(Name, X, Y, W, H) {
	x = X;
	y = Y;
	dx = 0.4;
	dy = 0.2;
	

	texture.loadFromImage(tm.getEnemyImg(3));
	sprite.setTexture(texture);
	sprite.setScale(0.5, 0.5); // масштаб

	spriteHeight = sprite.getTextureRect().height; // Высота спрайта
	spriteWidth = sprite.getTextureRect().width; // Ширина спрайта	

	
}
void HardEnemy::dv(float time) {
	
	if (x >= 960 || x <= 60) {
		
		dx = dx*(-1);
		//dy = dy*(-1);
	}
	if (y >= 250 || y <= 20 ){
		dy = dy*(-1);
	}

	x += dx*time;
	y += dy*time;

	while (x > 965)
	{
		//x = x - dx*time;
		x = 959;
	}

	while (x < 55) {
		//x = x + dx*time;
		x = 61;
	}

	while (y > 255)
	{
		//y = y - dy*time;
		y = 249;
	}

	while (y < 15) {
		//y = y + dy*time;
		y = 21;
	}

	

	sprite.setPosition(x, y);
}
