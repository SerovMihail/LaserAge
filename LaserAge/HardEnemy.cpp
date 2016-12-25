#include "HardEnemy.h"
#include <SFML/Graphics.hpp>
#include "TextureManager.h"

HardEnemy::HardEnemy(String Name, float X, float Y, int W, int H) :Enemy(Name, X, Y, W, H) {
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
void HardEnemy::update(float time ,int width, int heigth) {
	
	if (y >= heigth - 280 || y <= (heigth - (heigth - 30))) {
		dy = dy*(-1);
	}
	if (x >= (width - 40) || x <= (width - (width - 40))) {

		dx = dx*(-1);
	}

	x = x + dx*time;
	y = y + dy*time;

	//while (x > 965)
	//{
	//	//x = x - dx*time;
	//	x = 959;
	//}

	//while (x < 55) {
	//	//x = x + dx*time;
	//	x = 61;
	//}

	//while (y > 255)
	//{
	//	//y = y - dy*time;
	//	y = 249;
	//}

	//while (y < 15) {
	//	//y = y + dy*time;
	//	y = 21;
	//}

	

	sprite.setPosition(x, y);
}
