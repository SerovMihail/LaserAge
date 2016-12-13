#pragma once
#include "Bullet.h"

class BigBullet :
	public Bullet
{
public:
	//BigBullet(Image & image, String Name, float X, float Y, int W, int H);
	//BigBullet(String Name, float X, float Y, TextureManager & tm, int DX, int DY);
	BigBullet(String Name, float X, float Y, int W, int H, TextureManager & tm, int DX, int DY);
	~BigBullet();
};

