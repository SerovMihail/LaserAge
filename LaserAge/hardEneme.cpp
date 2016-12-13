#include "hardEneme.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list> 
#include <algorithm> 
#include "Entity.h"

hardEneme::hardEneme(String Name, float X, float Y, int W, int H, TextureManager & tm) :Enyme(Name, X, Y, W, H, tm) {
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
void hardEneme::dv() {
	x = x + dx;
	y = y + dy;
	if (x >= 960 || x <= 40) {
		//t1 = 0;
		dx = dx*(-1);
		dy = dy*(-1);
	}
	if (y>=250){
		dy = dy*(-1);
	}
	sprite.setPosition(x, y);
}
