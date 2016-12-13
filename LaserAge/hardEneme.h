#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list> 
#include <algorithm> 
#include "Enyme1.h"
#include "Entity.h"
#pragma once
class hardEneme :public Enyme
{
public:
	//hardEneme(Image &image, float X, float Y, int HEALTH);
	//hardEneme(String Name, float X, float Y, int W, int H, TextureManager & tm, int HEALTH);
	hardEneme(String Name, float X, float Y, int W, int H, TextureManager & tm);
	void hardEneme::dv();
};

