#include "Bullet.h"
#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include "TextureManager.h"

using namespace sf;

Bullet::Bullet(String Name, float X, float Y, int W, int H):GameObject(Name, X, Y, W, H)
{
	dy = 0.25; // скорость для всех пуль
	speed = dy;

	//spriteHeight = sprite.getTxtureRect().height; // Высота спрайта
	//spriteWidth = sprite.getTxtureRect().width; // Ширина спрайта	
	
}

void Bullet::update(float time) {
	y -= speed*time;
	
	sprite.setPosition(x, y);
}


Bullet::~Bullet()
{
}
