#pragma once
#include "Container.h"
class ContainerBullet :
	public Container
{
public:
	//ContainerBullet(Image &image, String Name, float X, float Y, int W, int H);
	//ContainerBullet(String Name, float X, float Y, TextureManager & tm);
	ContainerBullet(String Name, float X, float Y, int W, int H, TextureManager & tm);
	~ContainerBullet();
};

