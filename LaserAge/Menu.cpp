#include "Menu.h"
#include <SFML/Graphics.hpp>
#include "TextureManager.h"

using namespace sf;

Menu::Menu(int widthWindow, int heightWindow)
{
	isMenu = true; // Мы в меню
	menuNum = 0; // Пункт меню

				 // Устанавливаем координаты кнопок. Адаптивно, в процентах
	xButtonStart = widthWindow / 2.5; yButtonStart = heightWindow * 0.4;
	xButtonAbout = widthWindow / 2.5; yButtonAbout = heightWindow * 0.5;
	xButtonExit = widthWindow / 2.5; yButtonExit = heightWindow * 0.6;
	// Устанавливаем положение кнопок и цвет
	tm.setButtonStart(xButtonStart, yButtonStart); tm.setButtonStartColor(Color(255, 255, 255));
	tm.setButtonAbout(xButtonAbout, yButtonAbout); tm.setButtonAboutColor(Color(255, 255, 255));
	tm.setButtonExit(xButtonExit, yButtonExit); tm.setButtonExitColor(Color(255, 255, 255));
	// Получаем ширину и высоту кнопки 
	heightButtonStart = tm.getButtonStart().getTextureRect().height; widthButtonStart = tm.getButtonStart().getTextureRect().width;
	heightButtonAbout = tm.getButtonAbout().getTextureRect().height; widthButtonAbout = tm.getButtonAbout().getTextureRect().width;
	heightButtonExit = tm.getButtonExit().getTextureRect().height; widthButtonExit = tm.getButtonExit().getTextureRect().width;



}

void Menu::Display(RenderWindow & window) {
	while (isMenu)
	{
		window.clear(Color(186, 73, 255));

		tm.setButtonStartColor(Color(255, 255, 255));
		tm.setButtonAboutColor(Color(255, 255, 255));
		tm.setButtonExitColor(Color(255, 255, 255));

		// Если кнопка мыши на одной из кнопок изменяем цвет
		if (IntRect(xButtonStart, yButtonStart, widthButtonStart, heightButtonStart).contains(Mouse::getPosition(window)))
		{
			tm.setButtonStart(xButtonStart, yButtonStart);
			tm.setButtonStartColor(Color(255, 113, 69));
			menuNum = 1;
		}
		if (IntRect(xButtonAbout, yButtonAbout, widthButtonAbout, heightButtonAbout).contains(Mouse::getPosition(window)))
		{
			tm.setButtonAbout(xButtonAbout, yButtonAbout);
			tm.setButtonAboutColor(Color(255, 113, 69));
			menuNum = 2;
		}
		if (IntRect(xButtonExit, yButtonExit, widthButtonExit, heightButtonExit).contains(Mouse::getPosition(window)))
		{
			tm.setButtonExit(xButtonExit, yButtonExit);
			tm.setButtonExitColor(Color(255, 113, 69));
			menuNum = 3;
		}

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
