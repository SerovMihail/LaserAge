#pragma once
#include "GameObject.h"
#include "TextureManager.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Container : public GameObject
{
public:
	//Container(Image &image, String Name, float X, float Y, int W, int H);
	//Container(String Name, float X, float Y, TextureManager & tm);
	Container(String Name, float X, float Y, int W, int H, TextureManager & tm);
	void update(float time);
	~Container();
};

