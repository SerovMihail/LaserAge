#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"


using namespace sf;

class HardEnemy :public Enemy
{
public:
	
	HardEnemy(String Name, float X, float Y, int W, int H);
	void update(float time, int width, int heigth);

};

