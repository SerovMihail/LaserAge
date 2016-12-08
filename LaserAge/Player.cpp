#include <SFML/Graphics.hpp>
#include "Player.h"
#include "IBullet.h"
#include "IGameObject.h"


using namespace sf;

Player::Player(Image &image, String Name, float X, float Y, int W, int H, int Health):IGameObject( image, Name, X, Y, W, H)
{
	bulletLvl = 1;
	playerScore = 0;
	life = 1;
	health = Health;

	sprite.setScale(0.5, 0.5); // масштаб


}

Player::~Player()
{
}

void Player::update(float time)
{
	// Просчитываем положение героя. Если он вышел за дозволенные границы, блокируем движение в этом направлении.
	// 0 - Направо, 1 - Налево, 3 - Наверх, 2 - Вниз.
	control();
	switch (dir)
	{
	case right: if (x < windowWidth - (spriteWidth / 2)) {
		dx = speed; dy = 0; x += dx*time;
		y += dy*time;  break;
	}
			else {
				break;
			}
	case left: if (x > 0) {
		dx = -speed; dy = 0; x += dx*time;
		y += dy*time; break;
	}
			else {
				break;
			}
	case down: if (y < windowHeight - (spriteHeight / 2)) {
		dx = 0; dy = speed; x += dx*time;
		y += dy*time; break;
	}
			else {
				break;
			}
	case up: if (y > 0) {
		dx = 0; dy = -speed; x += dx*time;
		y += dy*time; break;
	}
			else {
				break;
			}
	}


	speed = 0; // Останавливаем движение корабля

	
	sprite.setPosition(x, y); // задаём его новое положение на экране
}



void Player::control() {
	// Задаём направление через - dir, скорость - speed. обновляем это относительно настоящих координат
	if (Keyboard::isKeyPressed(Keyboard::A)) { dir = left; speed = 0.5;  }
	if (Keyboard::isKeyPressed(Keyboard::D)) { dir = right; speed = 0.5; }
	if (Keyboard::isKeyPressed(Keyboard::W)) { dir = up; speed = 0.5; }
	if (Keyboard::isKeyPressed(Keyboard::S)) { dir = down; speed = 0.5; }
	if (Keyboard::isKeyPressed(Keyboard::Space)) { ; }

}

