#pragma once
#include <SFML/Graphics.hpp>
#include <iostream> 
#include <sstream>
#include "IGameObject.h"

using namespace sf;

class Player:public IGameObject {
protected:
	enum { left, right, up, down } dir;//��������� ��� ������������ - ��������� �������( ��� ����������� )
	int health, playerScore, life; // ���������� ������
	int bulletLvl;

public:
	
	Player(Image &image, String Name, float X, float Y, int W, int H, int Health); // ����� ������ �������, ��������� �� ������
	void update(float time); // �������� � �������


	int& Player::getScore(Player & p) const {
		return p.playerScore;
	}
	int& Player::getLife(Player & p) const {
		return p.life;
	}
	int& Player::getHealth(Player & p) const {
		return p.health;
	}
	void addLife() { life++; };
	int getBulletLvl() const { return bulletLvl; };
	void updateBullets(int lvl) { bulletLvl++; };
	void control();	
	~Player();	

};
