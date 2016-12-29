#include "LaserBullet.h"
#include "Bullet.h"
#include "TextureManager.h"



LaserBullet::LaserBullet(String Name, float X, float Y, int W, int H):Bullet(Name, X, Y, W, H)
{
	//texture.loadFromImage(tm.getBulletImg(1) );
	sprite.setTexture(*tm.get("bullet1"));
	sprite.setScale(0.5, 0.5); // масштаб

	spriteHeight = sprite.getTextureRect().height; // Высота спрайта
	spriteWidth = sprite.getTextureRect().width; // Ширина спрайта	

	damage = 30;

}


LaserBullet::~LaserBullet()
{
}
