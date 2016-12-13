#include "easyEneme.h"
#include "Enyme1.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list> 
#include <algorithm> 
#include "TextureManager.h"


Eneme1::Eneme1(String Name, float X, float Y, int W, int H, TextureManager & tm):Enyme(Name, X, Y, W, H, tm)
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
	void Eneme1::dv() {


		x = x + dx;

		if (x >= 960 || x <= 40) {
//			t1 = 0;
			dx = dx*(-1);
		}
		sprite.setPosition(x, y);
	}


