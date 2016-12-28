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
	dy = 0.2;

	
	
	texture.loadFromImage(tm.getEnemyImg(2));
	sprite.setTexture(texture);
	sprite.setScale(0.5, 0.5); // масштаб

	spriteHeight = sprite.getTextureRect().height; // Высота спрайта
	spriteWidth = sprite.getTextureRect().width; // Ширина спрайта	
}
	

void NormalEnemy::update(float time) {

	x = x + dx*time;
	y = y + dy*time;
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


