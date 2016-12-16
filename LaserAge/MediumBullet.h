#pragma once
#include "Bullet.h"
class MediumBullet :
	public Bullet
{
public:
	
	MediumBullet(String Name, float X, float Y, int W, int H);
	~MediumBullet();
};

