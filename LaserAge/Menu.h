#pragma once
#include <SFML/Graphics.hpp>
#include "TextureManager.h"

using namespace sf;

class Menu
{
private:		
	bool isMenu;
	int menuNum;

public:	
	Menu(RenderWindow & window, int widthWindow, int heightWindow);
	~Menu();
};

