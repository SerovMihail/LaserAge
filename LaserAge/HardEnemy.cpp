#include "HardEnemy.h"
#include <SFML/Graphics.hpp>
#include "TextureManager.h"

HardEnemy::HardEnemy(String Name, float X, float Y, int W, int H) :Enemy(Name, X, Y, W, H) {
	x = X;
	y = Y;
	dx = 0.5;
	dy = 0.2;

	windowHeight = H;
	windowWidth = W;

	texture.loadFromImage(tm.getEnemyImg(3));
	sprite.setTexture(texture);
	sprite.setScale(0.4, 0.4); // масштаб

	spriteHeight = sprite.getTextureRect().height; // Высота спрайта
	spriteWidth = sprite.getTextureRect().width; // Ширина спрайта	

	
}
<<<<<<< HEAD

void HardEnemy::update(float time) {
	
	if (y >= windowHeight - 280 || y <= (windowHeight - (windowHeight - 30))) {
		dy = dy*(-1);
	}
	if (x >= (windowWidth - 40) || x <= (windowWidth - (windowWidth - 40))) {
=======
void HardEnemy::update(int time ,int width, int heigth) {
	x = x + dx*time;
	y = y + dy*time;
	if (y >= (heigth - 280) || y <= (heigth - (heigth - 30))) {
		dy = dy*(-1);
	}
	if (x >= (width - 100) || x <= (width - (width - 40))) {
>>>>>>> origin/master

		dx = dx*(-1);
	}

	while (x >(width - 90))
	{
		x = (width - 110);

	}

	while (x < (width - (width - 30))) {
		x = (width - (width - 50));
	}

	while (y >(heigth - 270))
	{
		y = (heigth - 290);

	}

	while (y <(heigth - (heigth - 20))) {
		y = (heigth - (heigth - 40));
	}
	

	sprite.setPosition(x, y);
}
