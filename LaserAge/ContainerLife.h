#pragma once
#include "Container.h"
#include "TextureManager.h"

class ContainerLife:public Container
{
public:
	
	ContainerLife(String Name, float X, float Y, int W, int H);
	~ContainerLife();
};

