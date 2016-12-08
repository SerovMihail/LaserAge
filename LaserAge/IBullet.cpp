#include "IBullet.h"
#include "IGameObject.h"
#include <SFML/Graphics.hpp>

using namespace sf;

IBullet::IBullet(Image &image, String Name, float X, float Y, int W, int H, int BulletLvl):IGameObject(image, Name, X, Y, W, H)
{
	if (BulletLvl == 1) { damage = 100; }
	if (BulletLvl == 2) { damage = 150; }
	if (BulletLvl == 3) { damage = 200; }
	
	speed = 1; dx = 0; dy = 1;
	
	
}

void IBullet::update(float time) {
	y -= speed;
	
	sprite.setPosition(x, y);
}


IBullet::~IBullet()
{
}
