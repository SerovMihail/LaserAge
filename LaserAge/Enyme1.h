
#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list> 
#include <algorithm> 

class Enyme :public GameObject
{

public:
	
	virtual void dv()=0;


	Enyme(String Name, float X, float Y, int W, int H, TextureManager & tm);

};

