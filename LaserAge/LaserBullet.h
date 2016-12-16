#pragma once
#include "Bullet.h"
class LaserBullet :
	public Bullet
{
public:
	

	LaserBullet(String Name, float X, float Y, int W, int H);
	~LaserBullet();
};

