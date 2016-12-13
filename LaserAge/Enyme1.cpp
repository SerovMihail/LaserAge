#include "Enyme1.h"
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list> 
#include <algorithm> 
#include "normalEneme.h"
#include "easyEneme.h"
#include "hardEneme.h"





Enyme::Enyme(String Name, float X, float Y, int W, int H, TextureManager & tm) :GameObject(Name, X, Y, W, H, tm) {
	
	/*texture.loadFromImage(tm.getEnemyImg(1));
	sprite.setTexture(texture);*/
	//sprite.setScale(0.5, 0.5); // масштаб

	//spriteHeight = sprite.getTextureRect().height; // Высота спрайта
	//spriteWidth = sprite.getTextureRect().width; // Ширина спрайта	

	

	//speed = 0; dx = 0; dy = 0;
	
}



