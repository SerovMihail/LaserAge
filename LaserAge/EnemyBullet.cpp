#include "EnemyBullet.h"
#include "Bullet.h"
#include "TextureManager.h"



EnemyBullet::EnemyBullet(String Name, float X, float Y, int W, int H, TextureManager & tm, int DX, int DY) :Bullet(Name, X, Y, W, H, tm, DX, DY)
{
	texture.loadFromImage(tm.getEnemyLaser1());
	sprite.setTexture(texture);
	sprite.setScale(0.5, 0.5); // масштаб

	spriteHeight = sprite.getTextureRect().height; // Высота спрайта
	spriteWidth = sprite.getTextureRect().width; // Ширина спрайта	

	damage = 30;
}


EnemyBullet::~EnemyBullet()
{
}
