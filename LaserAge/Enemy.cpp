#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list> 
#include <algorithm> 
#include "NormalEnemy.h"
#include "EasyEnemy.h"
#include "HardEnemy.h"



using namespace sf;

Enyme::Enyme(String Name, float X, float Y, int W, int H) :GameObject(Name, X, Y, W, H) {
	
	/*texture.loadFromImage(tm.getEnemyImg(1));
	sprite.setTexture(texture);*/
	//sprite.setScale(0.5, 0.5); // масштаб

	//spriteHeight = sprite.getTextureRect().height; // Высота спрайта
	//spriteWidth = sprite.getTextureRect().width; // Ширина спрайта	
	

	//speed = 0; dx = 0; dy = 0;
	
}



