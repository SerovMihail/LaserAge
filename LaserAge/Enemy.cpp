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

Enemy::Enemy(String Name, float X, float Y, int W, int H) :GameObject(Name, X, Y, W, H) {
	
	/*txture.loadFromImage(tm.getEnemyImg(1));
	sprite.setTxture(txture);*/
	//sprite.setScale(0.5, 0.5); // �������

	//spriteHeight = sprite.getTxtureRect().height; // ������ �������
	//spriteWidth = sprite.getTxtureRect().width; // ������ �������	
	

	//speed = 0; dx = 0; dy = 0;
	
}



