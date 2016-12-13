#pragma once
#include "Bullet.h"
class EnemyBullet :
	public Bullet
{
public:
	//EnemyBullet();
	//EnemyBullet(String Name, float X, float Y, TextureManager & tm, int DX, int DY);
	EnemyBullet(String Name, float X, float Y, int W, int H, TextureManager & tm, int DX, int DY);
	~EnemyBullet();
};

