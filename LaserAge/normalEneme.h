#include "Entity.h"
#include "Enyme1.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list> 
#include <algorithm> 
#pragma once
class normalEneme:public Enyme
{
public:
	//normalEneme(Image &image, float X, float Y, int HEALTH);
	//normalEneme(String Name, float X, float Y, int W, int H, TextureManager & tm, int HEALTH);
	normalEneme(String Name, float X, float Y, int W, int H, TextureManager & tm);
	void normalEneme::dv();
};

