#include "EnemyBullet.h"
#include "Bullet.h"
#include "TextureManager.h"



EnemyBullet::EnemyBullet(String Name, float X, float Y, int W, int H) :Bullet(Name, X, Y, W, H)
{
	speed *= (-1);

	texture.loadFromImage(tm.getEnemyLaser1());
	sprite.setTexture(texture);
	sprite.setScale(0.5, 0.5); // �������

	spriteHeight = sprite.getTextureRect().height; // ������ �������
	spriteWidth = sprite.getTextureRect().width; // ������ �������	

	damage = 30;
}


EnemyBullet::~EnemyBullet()
{
}
