#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

using namespace sf;

class GameObject;
class Enemy :public GameObject
{

public:
	
	virtual void update(int time, int width, int heigth)=0;


	

	Enemy(String Name, float X, float Y, int W, int H);

};

