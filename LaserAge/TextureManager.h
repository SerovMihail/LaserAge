#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

using namespace sf;

class Player; // ������ ��� ��� ������ �� �����
class TextureManager
{
private:
	Image defaultImg;
	Image easyEnemy, normalEnemy, hardEnemy; // ������� �����
	Image ship; // ������� ������
	Image laser, normalLaser, bigLaser; // ���� ������ 
	Image ContainerLife, ContainerBullet; // ����������
	Image enemyLaser; // ���� ����� 
	Text text, title, textAbout, gameOver, youWin; // ��� ��������� ���������� � ����
	Texture menuTexture1, menuTexture2, menuTexture3, bg; // �������� ����
	Sprite menu1, menu2, menu3, about, bgSprite; // ������� ����

	Font font; // ����� ������������ � ����  Bungee-Regular.ttf

	// ���������� ��� ������������� ����������� ������������� ������
	std::ostringstream playerHealthString, gameTimeString, playerLifeString, playerScoreString;   
	std::ostringstream xStr, yStr;

public:
	TextureManager(int widthWindow, int heightWindow);

	// �� ��� ������� � ����
	void setButtonStart(int widthWindow, int heightWindow, Color color);
	void setButtonAbout(int x, int y, Color color);
	void setButtonExit(int x, int y, Color color);
	Sprite getButtonStart() const { return menu1; }
	Sprite getButtonAbout() const { return menu2; }
	Sprite getButtonExit() const { return menu3; }

	// ������� ��������
	Sprite getBackgroundTexture() const { return bgSprite; }
	Image getPlayerImg() const { return ship; }
	Image getEnemyLaser1() const { return enemyLaser; }
	Image getDefaultImg() const {return defaultImg; }
	Image getBulletImg(int lvl) const;
	Image getContainerImg(String name) const;
	Image getEnemyImg(int lvl) const;

	// ������ � ���������� �����������
	void setText(Player & p);
	Text getText() const {	return text; };
	Text getTextGameOver() const {	return gameOver; };
	Text getWinText() const {	return youWin;	};
	Text getTitleText() const {	return title;	};
	Text getTextAbout() const {	return textAbout;	};
	Font getFont() const { return font; };

	~TextureManager();
};

