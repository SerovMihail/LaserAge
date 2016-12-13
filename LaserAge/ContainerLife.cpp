#include "ContainerLife.h"
#include "TextureManager.h"
#include "Container.h"



ContainerLife::ContainerLife(/*Image &image, */String Name, float X, float Y, int W, int H, TextureManager & tm/*, int W, int H*/):Container(Name,X, Y , W, H, tm)
{
	texture.loadFromImage(tm.getContainerImg("life"));
	sprite.setTexture(texture);
	sprite.setScale(0.7, 0.7); // �������

	spriteHeight = sprite.getTextureRect().height; // ������ �������
	spriteWidth = sprite.getTextureRect().width; // ������ �������	
}


ContainerLife::~ContainerLife()
{
}
