#pragma once
#include "GameObject.h"
#include "TextureManager.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Container : public GameObject
{
public:
	
	Container(String Name, float X, float Y, int W, int H);
	virtual void update(float time);
	~Container();
};

