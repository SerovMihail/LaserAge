#include "Container.h"
#include "GameObject.h"
#include "TextureManager.h"
#include <SFML/Graphics.hpp>


using namespace sf;

Container::Container(String Name, float X, float Y, int W, int H) :GameObject(Name, X, Y, W, H)
{
	texture.loadFromImage(tm.getDefaultImg());
	speed = 0.4; dy = 0.4; 
	sprite.setScale(0.7, 0.7);
	
}

void Container::update(float time) {
	y += speed;

	sprite.setPosition(x, y);
}


Container::~Container()
{
}
