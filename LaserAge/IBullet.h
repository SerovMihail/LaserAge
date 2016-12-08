#pragma once
#include <SFML/Graphics.hpp>
#include "IGameObject.h"

using namespace sf;

class IBullet:public IGameObject {

protected:
	int damage;
	int bulletLvl;
	
public:
	
	IBullet(Image &image, String Name, float X, float Y, int W, int H, int BulletLvl);
	void update(float time);

	~IBullet();
};

