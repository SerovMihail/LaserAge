#include "BigBullet.h"
#include "TextureManager.h"



BigBullet::BigBullet(String Name, float X, float Y, int W, int H) :Bullet(Name, X, Y, W, H)
{
	//texture.loadFromImage(tm.getBulletImg(3));
	sprite.setTexture(*tm.get("bullet3"));
	sprite.setScale(1.2, 1.2);

	spriteHeight = sprite.getTextureRect().height; // ������ �������
	spriteWidth = sprite.getTextureRect().width; // ������ �������	

	damage = 200;
}


BigBullet::~BigBullet()
{
}
