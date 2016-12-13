#pragma once
#include <SFML/Graphics.hpp>
#include <iostream> 
#include <sstream>
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
#include "Enyme1.h"

using namespace sf;



class GameManager	{
private:	
	Window window;
	Clock spawnTimeClock, clock, gameTimeClock;

	int widthWindow, heightWindow;

	int level;
	bool next;
	//int score, health, life;
	
	int gameTime; // ����� � ���� � ��������
	float spawnTime; // ������ ������ ( ���� ������ ��� ����������� )
	float fpsTime; // ��� ������� �������������� �� �������� ��

	std::list<Bullet*>  bullet;// ������ ����
	std::list<Bullet*>::iterator it;//�������� ����� ��������� �� ��-��� ������

	std::list<Container*>  bonus;//������ �������
	std::list<Container*>::iterator bt;//�������� ����� ��������� �� ��-��� ������

	std::list<Enyme*>  entities;//������ ������, ���� ���� ������ ������� ������.
	std::list<Enyme*>::iterator et;//�������� ����� ��������� �� ��-��� ������

	std::list<Bullet*>  ebullet;//������ ������, ���� ���� ������ ������� ������.
	std::list<Bullet*>::iterator ebt;//�������� ����� ��������� �� ��-��� ������

public:
	
	

	GameManager();

	bool play(int level);
	
	//void update(Player & p);
	void update(Player & p, TextureManager & tm);
	// �������� ����������, ���������� ������������, ����� �� ������� ������
	void tickTime(); // ��� �������
	void runContainer(float spawntime, TextureManager & tm);

	void selectWeapon(int weaponLvl, TextureManager & tm, Player & p);
	void selectLvl(int lvl);

	void startNewLvl();

	void gameRunning(int Level);

	//void gameRunning();

	//void gameRunning(int level);

	//void gameRunning(int & level);

	~GameManager();
};


