#pragma once
#include "Bullet.h"
class MediumBullet :
	public Bullet
{
public:
	//MediumBullet(Image & image, String Name, float X, float Y, int W, int H);
	//MediumBullet(String Name, float X, float Y, TextureManager & tm, int DX, int DY);
	MediumBullet(String Name, float X, float Y, int W, int H, TextureManager & tm, int DX, int DY);
	~MediumBullet();
};

