#include "ContainerLife.h"
#include "TextureManager.h"
#include "Container.h"



ContainerLife::ContainerLife(String Name, float X, float Y, int W, int H):Container(Name,X, Y , W, H)
{
	//texture.loadFromImage(tm.getContainerImg("life"));
	sprite.setTexture(*tm.get("containerLife"));
	sprite.setScale(0.7, 0.7); // �������

	spriteHeight = sprite.getTextureRect().height; // ������ �������
	spriteWidth = sprite.getTextureRect().width; // ������ �������	
}


ContainerLife::~ContainerLife()
{
}
