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

	sprite.setScale(0.5, 0.5); // �������


}

Player::~Player()
{
}

void Player::update(float time)
{
	// ������������ ��������� �����. ���� �� ����� �� ����������� �������, ��������� �������� � ���� �����������.
	// 0 - �������, 1 - ������, 3 - ������, 2 - ����.
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


	speed = 0; // ������������� �������� �������

	
	sprite.setPosition(x, y); // ����� ��� ����� ��������� �� ������
}



void Player::control() {
	// ����� ����������� ����� - dir, �������� - speed. ��������� ��� ������������ ��������� ���������
	if (Keyboard::isKeyPressed(Keyboard::A)) { dir = left; speed = 0.5;  }
	if (Keyboard::isKeyPressed(Keyboard::D)) { dir = right; speed = 0.5; }
	if (Keyboard::isKeyPressed(Keyboard::W)) { dir = up; speed = 0.5; }
	if (Keyboard::isKeyPressed(Keyboard::S)) { dir = down; speed = 0.5; }
	if (Keyboard::isKeyPressed(Keyboard::Space)) { ; }

}

