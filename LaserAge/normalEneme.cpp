#include "normalEneme.h"
#include "Entity.h"
#include "Enyme1.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list> 
#include <algorithm> 

normalEneme::normalEneme(String Name, float X, float Y, int W, int H, TextureManager & tm) :Enyme(Name, X, Y, W, H, tm) {
	x = X;
	y = Y;


	dx = 0.3;
	dy = 0.3;

	
	
	texture.loadFromImage(tm.getEnemyImg(2));
	sprite.setTexture(texture);
	sprite.setScale(0.5, 0.5); // �������

	spriteHeight = sprite.getTextureRect().height; // ������ �������
	spriteWidth = sprite.getTextureRect().width; // ������ �������	
}
void normalEneme::dv() {
	x = x + dx;
	y = y + dy;
	if (y >= 250 || y <= 10) {
		dy = dy*(-1);
	}
	if (x >= 960 || x <= 40) {
		//t1 = 0;
		dx = dx*(-1);
	}
	sprite.setPosition(x, y);
}


