#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

using namespace sf;

class Player; // ������ ��� ��� ������ �� �����
class TextureManager
{
private:
	Texture defaultImg; // ��������
	Texture easyEnemy, normalEnemy, hardEnemy; // ������� �����
	Texture ship; // ������� ������
	Texture laser, normalLaser, bigLaser; // ���� ������ 
	Texture ContainerLife, ContainerBullet; // ����������
	Texture enemyLaser; // ���� ����� 
	Text text, title, txtAbout, gameOver, youWin; // ��� ��������� ���������� � ����
	Texture menuTexture1, menuTexture2, menuTexture3, bg; // �������� ����
	Sprite menu1, menu2, menu3, about, bgSprite; // ������� ����
	
	

	Font font; // ����� ������������ � ����  Bungee-Regular.ttf

	// ���������� ��� ������������� ����������� ������������� ������
	std::ostringstream playerHealthString, gameTimeString, playerLifeString, playerScoreString;   
	std::ostringstream xStr, yStr;
	/*Image &Sh = getPlayerImg();*/
public:
	TextureManager(int widthWindow, int heightWindow);

	// �� ��� ������� � ����
	void setButtonStart(int x, int y); void setButtonStartColor(Color color);
	void setButtonAbout(int x, int y);  void setButtonAboutColor(Color color);
	void setButtonExit(int x, int y);  void setButtonExitColor(Color color);
	Sprite getButtonStart() const { return menu1; }
	Sprite getButtonAbout() const { return menu2; }
	Sprite getButtonExit() const { return menu3; }

	// ������� ��������
	Sprite getBackgroundTexture() const { return bgSprite; }
	Texture * get(const char * name);
	/*Image getPlayerImg() const { return ship; }
	Image getEnemyLaser1() const { return enemyLaser; }
	Image getDefaultImg() const {return defaultImg; }
	Image getBulletImg(int lvl) const;
	Image getContainerImg(String name) const;
	Image getEnemyImg(int lvl) const;
	
	Image &Sh = ship;
	Sprite &bgt=bgSprite;
	Image &eL = enemyLaser;
	Image &di = defaultImg;*/
	// ������ � ���������� �����������
	void setText(Player & p);
	Text getText() const {	return text; };
	Text getTextGameOver() const {	return gameOver; };
	Text getWinText() const {	return youWin;	};
	Text getTitleText() const {	return title;	};
	Text getTextAbout() const {	return txtAbout;	};
	Font getFont() const { return font; };

	~TextureManager();
	//TextureManager(int widthWindow, int heightWindow);
};

extern TextureManager tm;
