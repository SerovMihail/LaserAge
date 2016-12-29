#include "MediumBullet.h"
#include "TextureManager.h"



MediumBullet::MediumBullet(String Name, float X, float Y, int W, int H) :Bullet(Name, X, Y, W, H)
{
	//texture.loadFromImage(tm.getBulletImg(2));
	sprite.setTexture(*tm.get("bullet2"));
	sprite.setScale(0.8, 0.8);

	spriteHeight = sprite.getTextureRect().height; // Высота спрайта
	spriteWidth = sprite.getTextureRect().width; // Ширина спрайта	

	damage = 150;
}


MediumBullet::~MediumBullet()
{
}
