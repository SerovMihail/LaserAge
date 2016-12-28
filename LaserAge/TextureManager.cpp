#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include "Player.h"

#include <iostream> 
#include <sstream>

using namespace sf;

TextureManager::TextureManager(int widthWindow, int heightWindow)
{		
	// 
	defaultImg.loadFromFile("images/default.png");

	// �������� ������
	ship.loadFromFile("images/orangePlayer.png");
	
	// �������� ��� �����
	laser.loadFromFile("images/laserRed.png"); 	// 1 ���
	normalLaser.loadFromFile("images/normalLaser.png"); // 2 ���
	bigLaser.loadFromFile("images/bigLaser.png"); // 3 ��� 

	// �������� ����������� "�����" � "������"
	ContainerLife.loadFromFile("images/containerLife.png");	
	ContainerBullet.loadFromFile("images/containerBullet.png");
	
	// �������� ������ � ������ 
	font.loadFromFile("Bungee-Regular.ttf");
	text.setFont(font);
	text.setCharacterSize(20);
	text.setStyle(Text::Bold | Text::Underlined);//������ � �����
	text.setPosition(10, 10);//������ ������� ������, ����� ������

	// �������� ����
	menuTexture1.loadFromFile("images/startButton.png");
	menu1.setTexture(menuTexture1);
	menuTexture2.loadFromFile("images/aboutButton.png");
	menu2.setTexture(menuTexture2);
	menuTexture3.loadFromFile("images/exitButton.png");
	menu3.setTexture(menuTexture3);
	
	// ��������� ����	
	title.setString("LaserAge");
	title.setFont(font);
	title.setCharacterSize(180);
	title.setStyle(Text::Bold | Text::Underlined);
	title.setPosition(0, 0);

	// ������ . ����, �����, ���� �������� ���� ���� � ���� ������, ���� �� ������� ��� :)))
	
	txtAbout.setString("Created by: \n\tSerov Mihail\n\tAlxander Karyapin\n\tArina Alferova\n\tBabenushev Ilya \nStudents of group 21317 \n\n\n 'ESC' return to menu");
	txtAbout.setFont(font);
	txtAbout.setCharacterSize(30);
	txtAbout.setStyle(Text::Bold | Text::Underlined);//������ � �����
	txtAbout.setPosition(widthWindow / 4, heightWindow / 4);//������ ������� ������, ����� ������
	

	// ������ ���
	bg.loadFromFile("images/purple.png");
	bg.setRepeated(true);
	bgSprite.setTexture(bg);
	bgSprite.setTextureRect(IntRect(0, 0, widthWindow, heightWindow));

	// �������� ������
	enemyLaser.loadFromFile("images/enemyLaser.png");
	easyEnemy.loadFromFile("images/space1.png");
	normalEnemy.loadFromFile("images/space2.png");
	hardEnemy.loadFromFile("images/space3.png");

	// ���� ���������
	gameOver.setString("Game Over\n\n Esc - Exit\n\n 'E' - Start New Game");
	gameOver.setFont(font);
	gameOver.setCharacterSize(30);
	gameOver.setStyle(Text::Bold | Text::Underlined);//������ � �����
	gameOver.setPosition(widthWindow / 4, heightWindow / 4);//������ ������� ������, ����� ������

	// ����������
	youWin.setString("You win!\n\n Esc - Exit\n\n 'E' - Start New Game");
	youWin.setFont(font);
	youWin.setCharacterSize(30);
	youWin.setStyle(Text::Bold | Text::Underlined);//������ � �����
	youWin.setPosition(widthWindow / 4, heightWindow / 4);//������ ������� ������, ����� ������
	
}

void TextureManager::setButtonStart(int x, int y) { menu1.setPosition(x, y); }
void TextureManager::setButtonStartColor(Color color) { menu1.setColor(Color(color)); }
void TextureManager::setButtonAbout(int x, int y) { menu2.setPosition(x, y); }
void TextureManager::setButtonAboutColor(Color color) { menu2.setColor(Color(color)); }
void TextureManager::setButtonExit(int x, int y) { menu3.setPosition(x, y); }
void TextureManager::setButtonExitColor(Color color) { menu3.setColor(Color(color)); }


Image TextureManager::getBulletImg(int lvl) const {
	switch (lvl)
	{
		case 1: {return laser; }
		case 2: { return normalLaser; }
		case 3: { return bigLaser; }
		default:
			std::cout << "Error on load bullet img";
			break;
	}
	
}

Image TextureManager::getContainerImg(String name) const {
	
	if (name == "life") { return ContainerLife;  }
	if (name == "bullet") { return ContainerBullet; }
}

Image TextureManager::getEnemyImg(int lvl) const
{
	switch (lvl)
	{
	case 1: { return easyEnemy;  }
	case 2: { return normalEnemy; }
	case 3: { return hardEnemy; }
	default:
		std::cout << "Error on load Enemy Img";
		break;
	}
	
}

void TextureManager::setText(Player & p) {
	// �������� �����
	xStr.str(""); 
	yStr.str("");
	playerHealthString.str("");
	playerLifeString.str("");
	playerScoreString.str("");

	xStr << p.getX(/*p*/);
	yStr << p.getY(/*p*/);
	playerHealthString << p.getHealth();
	//gameTimeString << spawnTime;// gameTime;
	playerLifeString << p.getLife();
	playerScoreString << p.getScore();

	//txt.setString("Score:" + playerScoreString.str()
	//	+ "\nHealth: " + playerHealthString.str()
	//	+ "\nSeconds in game: " + gameTimeString.str()
	//	+ "\nLife: " + playerLifeString.str()
	//	+ "\nx: " + xStr.str() + "\ny: " + yStr.str());//������ ������ ������ � �������� �������������� ���� ������ ������� .str()

	text.setString("Score:" + playerScoreString.str()
		+ "\nHealth: " + playerHealthString.str()
		+ "\nLife: " + playerLifeString.str());

}




TextureManager::~TextureManager()
{
}




TextureManager tm(1000, 500);
