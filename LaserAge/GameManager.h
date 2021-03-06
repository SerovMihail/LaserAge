#pragma once
#include <SFML/Graphics.hpp>
#include <iostream> 
#include <sstream>
#include "Menu.h"
#include "Player.h"
#include "Bullet.h"
#include "GameObject.h"
#include "Container.h"
#include "TextureManager.h"
#include <list>
#include <iterator>
#include <vector>
#include <ctime>
#include "GameManager.h"
#include "Enemy.h"

using namespace sf;



class GameManager	{
private:	
	// ���������� �����
	Menu m;
	Player p;

	Window window;
	Clock spawnTimeClock, clock, gameTimeClock;

	int widthWindow, heightWindow;

	int level, maxLvl;
	bool next;
	bool restartGame;
	float ex, ey, ds;//sd-���������� ����
	bool runL, runB;
	//int score, health, life;
	
	int gameTime; // ����� � ���� � ��������
	float spawnTime; // ������ ������ ( ���� ������ ��� ����������� )
	float fpsTime; // ��� ������� �������������� �� �������� ��

	std::list<Bullet*>  bullet;// ������ ����
	std::list<Bullet*>::iterator it;//�������� ����� ��������� �� ��-��� ������

	std::list<Container*>  bonus;//������ �������
	std::list<Container*>::iterator bt;//�������� ����� ��������� �� ��-��� ������

	std::list<Enemy*>  entities;//������ ������, ���� ���� ������ ������� ������.
	std::list<Enemy*>::iterator et;//�������� ����� ��������� �� ��-��� ������

	std::list<Bullet*>  ebullet;//������ ������, ���� ���� ������ ������� ������.
	std::list<Bullet*>::iterator ebt;//�������� ����� ��������� �� ��-��� ������

public:
	GameManager(int W, int H);

	bool play(int & Level);

	void clearAllContainer();
	
	void update(Player & p);
	// �������� ����������, ���������� ������������, ����� �� ������� ������
	void tickTime(); // ��� �������

	void runContainer(float spawntime);	

	void selectWeapon(int weaponLvl, Player & p);

	void selectLvl(int lvl);	

	void gameRunning(int & Level);

	void draw(RenderWindow & window, Player & p);

	

	~GameManager();
};


