#pragma once
#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list> 
#include <algorithm> 
#include "TextureManager.h"
#include "GameManager.h"
class EasyEnemy: public Enemy
{
public:
	
	
	EasyEnemy(String Name, float X, float Y, int W, int H);
	void update(float time, int width, int heigth);
	//std::list<Bullet*>  ebullet;//������ ������, ���� ���� ������ ������� ������.
	//std::list<Bullet*>::iterator ebt;//�������� ����� ��������� �� ��-��� ������
};

