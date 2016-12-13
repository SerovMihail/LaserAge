#include "Entity.h"
#include "Enyme1.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list> 
#include <algorithm> 
#include "TextureManager.h"
#pragma once
class Eneme1: public Enyme
{
public:
	//Eneme1(Image &image, float X, float Y, int HEALTH);
	//Eneme1(Image & image, float X, float Y, int HEALTH, TextureManager & tm);
	Eneme1(String Name, float X, float Y, int W, int H, TextureManager & tm);
	void Eneme1::dv();
};

