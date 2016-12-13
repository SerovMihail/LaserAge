#include "Menu.h"
#include <SFML/Graphics.hpp>
#include "TextureManager.h"

using namespace sf;

Menu::Menu(RenderWindow & window, int widthWindow, int heightWindow, TextureManager & tm)
{

	bool isMenu = true; // Мы в меню
	int menuNum = 0; // Пункт меню
	

	//////////////////////////////МЕНЮ///////////////////
	while (isMenu)
	{
		tm.setButtonStart(widthWindow / 2.5, heightWindow * 0.4, Color::White);
		tm.setButtonAbout(widthWindow / 2.5, heightWindow * 0.5, Color::White);
		tm.setButtonExit(widthWindow / 2.5, heightWindow * 0.6, Color::White);

		menuNum = 0;
		window.clear(Color(186, 73, 255));


		if (IntRect(tm.getButtonStart().getPosition().x, tm.getButtonStart().getPosition().y, tm.getButtonStart().getTextureRect().width, tm.getButtonStart().getTextureRect().height).contains(Mouse::getPosition(window))) { tm.setButtonStart(widthWindow / 2.5, heightWindow * 0.4, Color::Color(255, 113, 69)); menuNum = 1; }
		if (IntRect(tm.getButtonAbout().getPosition().x, tm.getButtonAbout().getPosition().y, tm.getButtonAbout().getTextureRect().width, tm.getButtonAbout().getTextureRect().height).contains(Mouse::getPosition(window))) { tm.setButtonAbout(widthWindow / 2.5, heightWindow * 0.5, Color::Color(255, 113, 69)); menuNum = 2; }
		if (IntRect(tm.getButtonExit().getPosition().x, tm.getButtonExit().getPosition().y, tm.getButtonExit().getTextureRect().width, tm.getButtonExit().getTextureRect().height).contains(Mouse::getPosition(window))) { tm.setButtonExit(widthWindow / 2.5, heightWindow * 0.6, Color::Color(255, 113, 69)); menuNum = 3; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 2) { window.draw(tm.getTextAbout()); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }
			if (menuNum == 3) { window.close(); isMenu = false; }

		}

		// отображаем все элементы меню
		window.draw(tm.getBackgroundTexture());
		window.draw(tm.getTitleText());
		window.draw(tm.getButtonStart());
		window.draw(tm.getButtonAbout());
		window.draw(tm.getButtonExit());
		window.display();
	}
	
}


Menu::~Menu()
{
}
