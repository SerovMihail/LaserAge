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
	
	int gameTime; // Время в игре в секундах
	float spawnTime; // Таймер спавна ( пока только для контейнеров )
	float fpsTime; // При отвязки быстродействия от ресурсов ПК

	std::list<Bullet*>  bullet;// список пуль
	std::list<Bullet*>::iterator it;//итератор чтобы проходить по эл-там списка

	std::list<Container*>  bonus;//список бонусов
	std::list<Container*>::iterator bt;//итератор чтобы проходить по эл-там списка

	std::list<Enyme*>  entities;//создаю список, сюда буду кидать объекты врагов.
	std::list<Enyme*>::iterator et;//итератор чтобы проходить по эл-там списка

	std::list<Bullet*>  ebullet;//создаю список, сюда буду кидать объекты врагов.
	std::list<Bullet*>::iterator ebt;//итератор чтобы проходить по эл-там списка

public:
	
	

	GameManager();

	bool play(int level);
	
	//void update(Player & p);
	void update(Player & p, TextureManager & tm);
	// Обновить координаты, посмотреть столкновения, выход на пределы экрана
	void tickTime(); // Тик таймера
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


