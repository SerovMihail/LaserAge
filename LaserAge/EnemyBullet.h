#pragma once
#include "Bullet.h"
class EnemyBullet :
	public Bullet
{
public:
	
	EnemyBullet(String Name, float X, float Y, int W, int H);
	~EnemyBullet();
};

