#pragma once
#include <SFML/Graphics.hpp>
#include <iostream> 
#include <sstream>
#include "GameObject.h"
#include "TextureManager.h"

using namespace sf;

//class GameObject;
//class TextureManager;
class Player:public GameObject {
protected:
	enum { left, right, up, down } dir;//добавляем тип перечисления - состояние объекта( его направление )
	int health, playerScore, life; // показатели игрока
	int bulletLvl;
	bool win;

public:	

	Player(String Name, float X, float Y, int W, int H, int Health);
	
	void update(float time); // привязка к времени

	bool getIAmAlive() const {
		if (iAmAlive == true) { return true; }
		else { return false; }
	}
	bool getWin() const {
		if (win == true) { return true; }
		else { return false; }
	}
	void setIAmAlive(bool live) {	iAmAlive = live;	}
	void setWin(bool victory) {	win = victory;	}
	int& getScore(Player & p) const {	return p.playerScore;	}
	int& getLife(Player & p) const {	return p.life;	}
	int& getHealth(Player & p) const {	return p.health;	}
	void addLife() { life++; };
	int getBulletLvl() const { return bulletLvl; };
	void updateBullets(int lvl) { bulletLvl++; };
	void damage(int damage) { health = health - damage; }
	void control();
	void addScore(int score);	

	~Player();

	void newGame();

};
