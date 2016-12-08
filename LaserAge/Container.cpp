#include "Container.h"
#include "IGameObject.h"
#include <SFML/Graphics.hpp>


using namespace sf;

Container::Container(Image &image, String Name, float X, float Y, int W, int H) :IGameObject(image, Name, X, Y, W, H)
{
	speed = 0.05; dy = 0.05;
	sprite.setScale(0.7, 0.7);
}

void Container::update(float time) {
	y += speed;

	sprite.setPosition(x, y);
}


Container::~Container()
{
}
