#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

using namespace sf;

class Bullet:public GameObject {

protected:
	int damage;
	int bulletLvl;
	
public:
	Bullet(String Name, float X, float Y, int W, int H);

	int makeDamage() { return damage; }
	
	void update(float time);

	~Bullet();
};

