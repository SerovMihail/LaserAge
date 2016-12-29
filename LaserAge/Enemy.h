#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

using namespace sf;

class GameObject;
class Enemy :public GameObject
{

public:	

	Enemy(String Name, float X, float Y, int W, int H);

	//void update(float time);

};

