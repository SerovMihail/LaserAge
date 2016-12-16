#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"


using namespace sf;

class HardEnemy :public Enyme
{
public:
	
	HardEnemy(String Name, float X, float Y, int W, int H);
	void dv(float time);

};

