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


void HardEnemy::update(float time) {
	
	if (y >= windowHeight - 280 || y <= (windowHeight - (windowHeight - 30))) {
		dy = dy*(-1);
	}
	if (x >= (windowWidth - 40) || x <= (windowWidth - (windowWidth - 40))) {


		dx = dx*(-1);
	}

	while (x >(windowWidth - 90))
	{
		x = (windowWidth - 110);

	}

	while (x < (windowWidth - (windowWidth - 30))) {
		x = (windowWidth - (windowWidth - 50));
	}

	while (y >(windowHeight - 270))
	{
		y = (windowHeight - 290);

	}

	while (y <(windowHeight - (windowHeight - 20))) {
		y = (windowHeight - (windowHeight - 40));
	}
	

	sprite.setPosition(x, y);
}
