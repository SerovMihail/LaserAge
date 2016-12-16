#pragma once
#include "Bullet.h"

class BigBullet :
	public Bullet
{
public:
	
	BigBullet(String Name, float X, float Y, int W, int H);
	~BigBullet();
};

