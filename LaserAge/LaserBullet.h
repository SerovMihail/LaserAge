#pragma once
#include "Bullet.h"
class LaserBullet :
	public Bullet
{
public:
	
	//LaserBullet(Image & image, String Name, float X, float Y, int W, int H);
	//LaserBullet(String Name, float X, float Y, TextureManager & tm, int DX, int DY);
	LaserBullet(String Name, float X, float Y, int W, int H, TextureManager & tm, int DX, int DY);
	~LaserBullet();
};

