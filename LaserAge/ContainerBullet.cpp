#include "ContainerBullet.h"
#include "TextureManager.h"



ContainerBullet::ContainerBullet(String Name, float X, float Y, int W, int H) :Container(Name, X, Y, W, H)
{
	//texture.loadFromImage(tm.getContainerImg("bullet"));
	sprite.setTexture(*tm.get("containerBullet"));
	sprite.setScale(0.7, 0.7); // масштаб

	spriteHeight = sprite.getTextureRect().height; // Высота спрайта
	spriteWidth = sprite.getTextureRect().width; // Ширина спрайта	
}


ContainerBullet::~ContainerBullet()
{
}
