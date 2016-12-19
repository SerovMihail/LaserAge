#pragma once
#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list> 
#include <algorithm> 
#include "TextureManager.h"

class EasyEnemy: public Enyme
{
public:
	
	
	EasyEnemy(String Name, float X, float Y, int W, int H);
	void dv(float time);

};

