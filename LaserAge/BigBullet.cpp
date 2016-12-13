#include "BigBullet.h"
#include "TextureManager.h"



BigBullet::BigBullet(String Name, float X, float Y, int W, int H, TextureManager & tm, int DX, int DY) :Bullet(Name, X, Y, W, H, tm, DX, DY)
{
	texture.loadFromImage(tm.getBulletImg(3));
	sprite.setTexture(texture);	
	sprite.setScale(1.2, 1.2);

	spriteHeight = sprite.getTextureRect().height; // Высота спрайта
	spriteWidth = sprite.getTextureRect().width; // Ширина спрайта	

	damage = 200;
}


BigBullet::~BigBullet()
{
}
