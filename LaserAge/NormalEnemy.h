#pragma once
#include "Enemy.h"
#include <SFML/Graphics.hpp>





using namespace sf;

class NormalEnemy:public Enemy
{
public:
	
	NormalEnemy(String Name, float X, float Y, int W, int H);

	void NormalEnemy::update(float time, int width, int heigth);
};

