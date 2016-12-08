#pragma once
#include "IGameObject.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Container : public IGameObject
{
public:
	Container(Image &image, String Name, float X, float Y, int W, int H);
	void update(float time);
	~Container();
};

