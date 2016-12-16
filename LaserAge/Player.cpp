#include <SFML/Graphics.hpp>
#include "Player.h"
#include "TextureManager.h"




Player::Player(String Name, float X, float Y, int W, int H, int Health):GameObject(Name, X, Y, W, H)
{
	texture.loadFromImage(tm.getPlayerImg());
	//texture.loadFromFile("images/orangePlayer.png");
	sprite.setTexture(texture);
	sprite.setScale(0.5, 0.5); // �������

	spriteHeight = sprite.getTextureRect().height; // ������ �������
	spriteWidth = sprite.getTextureRect().width; // ������ �������	

	bulletLvl = 1;
	playerScore = 0;
	life = 1;
	health = Health;
	win = false;
}

Player::~Player()
{

}

void Player::newGame() {

	x = windowWidth / 2;
	y = windowHeight * 0.8;

	bulletLvl = 1;
	playerScore = 0;
	life = 1;
	health = 100;
	

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
			case up: if (y > (windowHeight / 2)) {
				dx = 0; dy = -speed; x += dx*time;
				y += dy*time; break;
			}
					else {
						break;
					}
	}

	if (health <= 0) { life--; health = 100; };
	if (life <= 0) { iAmAlive = false;	}

	speed = 0; // ������������� �������� �������

	
	sprite.setPosition(x, y); // ����� ��� ����� ��������� �� ������
}



void Player::control() {
	// ����� ����������� ����� - dir, �������� - speed. ��������� ��� ������������ ��������� ���������
	if (Keyboard::isKeyPressed(Keyboard::A)) { dir = left; speed = 0.5; /*std::cout << "left\n";*/ }
	if (Keyboard::isKeyPressed(Keyboard::D)) { dir = right; speed = 0.5; /*std::cout << "right\n";*/	}
	if (Keyboard::isKeyPressed(Keyboard::W)) { dir = up; speed = 0.5;  /*std::cout << "up\n";*/	}
	if (Keyboard::isKeyPressed(Keyboard::S)) { dir = down; speed = 0.5; /*std::cout << "down\n";*/	}

}

void Player::addScore(int score) {
	playerScore += score;
}
