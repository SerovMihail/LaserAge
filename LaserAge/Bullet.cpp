#include "Bullet.h"
#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include "TextureManager.h"

using namespace sf;

Bullet::Bullet(String Name, float X, float Y, int W, int H, TextureManager & tm, int DX, int DY):GameObject(Name, X, Y, W, H, tm)
{
	
	//texture.loadFromImage(tm.getDefaultImg());
	//sprite.setTexture(texture);
	//sprite.setScale(0.5, 0.5); // �������

	spriteHeight = sprite.getTextureRect().height; // ������ �������
	spriteWidth = sprite.getTextureRect().width; // ������ �������	

	speed = DY;
	
}

void Bullet::update(float time) {
	y -= speed;
	
	sprite.setPosition(x, y);
}


Bullet::~Bullet()
{
}
