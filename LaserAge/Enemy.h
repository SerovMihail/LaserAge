#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

using namespace sf;

class GameObject;
class Enyme :public GameObject
{

public:
	
	virtual void dv(float time)=0;


	

	Enyme(String Name, float X, float Y, int W, int H);

};

