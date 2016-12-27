#pragma once
#include <SFML/Graphics.hpp>
#include "TextureManager.h"

using namespace sf;

class Menu
{
private:		
	bool isMenu;
	int menuNum;

	float xButtonStart, yButtonStart, widthButtonStart, heightButtonStart;
	float xButtonAbout, yButtonAbout, widthButtonAbout, heightButtonAbout;
	float xButtonExit, yButtonExit, widthButtonExit, heightButtonExit;

public:	
	Menu(int widthWindow, int heightWindow);
	void Display(RenderWindow & window);
	~Menu();
};

