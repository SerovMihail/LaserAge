#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

using namespace sf;

class Player; // Потому что исп ссылку на класс
class TextureManager
{
private:
	Image defaultImg;
	Image easyEnemy, normalEnemy, hardEnemy; // Корабли врага
	Image ship; // корабль игрока
	Image laser, normalLaser, bigLaser; // Пули игрока 
	Image ContainerLife, ContainerBullet; // Контейнеры
	Image enemyLaser; // Пули врага 
	Text text, title, textAbout, gameOver, youWin; // Все текстовые переменные в игре
	Texture menuTexture1, menuTexture2, menuTexture3, bg; // Текстуры меню
	Sprite menu1, menu2, menu3, about, bgSprite; // спрайты меню

	Font font; // Шрифт используемые в игре  Bungee-Regular.ttf

	// Переменные для динамического отображения характеристик игрока
	std::ostringstream playerHealthString, gameTimeString, playerLifeString, playerScoreString;   
	std::ostringstream xStr, yStr;

public:
	TextureManager(int widthWindow, int heightWindow);

	// Всё что связано с меню
	void setButtonStart(int widthWindow, int heightWindow, Color color);
	void setButtonAbout(int x, int y, Color color);
	void setButtonExit(int x, int y, Color color);
	Sprite getButtonStart() const { return menu1; }
	Sprite getButtonAbout() const { return menu2; }
	Sprite getButtonExit() const { return menu3; }

	// Игровые текстуры
	Sprite getBackgroundTexture() const { return bgSprite; }
	Image getPlayerImg() const { return ship; }
	Image getEnemyLaser1() const { return enemyLaser; }
	Image getDefaultImg() const {return defaultImg; }
	Image getBulletImg(int lvl) const;
	Image getContainerImg(String name) const;
	Image getEnemyImg(int lvl) const;

	// Работа с текстовыми переменными
	void setText(Player & p);
	Text getText() const {	return text; };
	Text getTextGameOver() const {	return gameOver; };
	Text getWinText() const {	return youWin;	};
	Text getTitleText() const {	return title;	};
	Text getTextAbout() const {	return textAbout;	};
	Font getFont() const { return font; };

	~TextureManager();
};

