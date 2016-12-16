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
#include "Enemy.h"

using namespace sf;



class GameManager	{
private:	
	Window window;
	Clock spawnTimeClock, clock, gameTimeClock;

	int widthWindow, heightWindow;

	int level, maxLvl;
	bool next;
	bool restartGame;
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

	bool play(int & Level);

	void clearAllContainer();
	
	void update(Player & p);
	// Обновить координаты, посмотреть столкновения, выход на пределы экрана
	void tickTime(); // Тик таймера

	void runContainer(float spawntime);	

	void selectWeapon(int weaponLvl, Player & p);

	void selectLvl(int lvl);	

	void gameRunning(int & Level);

	void draw(RenderWindow & window, Player & p);

	

	~GameManager();
};


