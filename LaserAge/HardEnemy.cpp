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
	x += dx*time;
	y += dy*time;
	if (x >= 900 || x <= 60) {
		//t1 = 0;
		dx = dx*(-1);
		dy = dy*(-1);
	}
	if (y>=250){
		dy = dy*(-1);
	}
	sprite.setPosition(x, y);
}
