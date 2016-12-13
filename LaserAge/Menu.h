#pragma once
#include <SFML/Graphics.hpp>
#include "TextureManager.h"

using namespace sf;

class Menu
{
private:
	//Texture menuTexture1, menuTexture2, menuTexture3, bg;
	
	Text title, textAbout;
	bool isMenu;
	int menuNum;
public:

	Menu(RenderWindow & window, int widthWindow, int heightWindow, TextureManager & tm);
	~Menu();
};

