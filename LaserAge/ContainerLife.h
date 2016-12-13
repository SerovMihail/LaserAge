#pragma once
#include "Container.h"
#include "TextureManager.h"

class ContainerLife:public Container
{
public:
	//ContainerLife(Image &image, String Name, float X, float Y, int W, int H);
	//ContainerLife(String Name, float X, float Y, TextureManager & tm);
	ContainerLife(String Name, float X, float Y, int W, int H, TextureManager & tm);
	~ContainerLife();
};

