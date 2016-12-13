#include "Container.h"
#include "GameObject.h"
#include "TextureManager.h"
#include <SFML/Graphics.hpp>


using namespace sf;

Container::Container(String Name, float X, float Y, int W, int H, TextureManager & tm) :GameObject(Name, X, Y, W, H, tm)
{
	texture.loadFromImage(tm.getDefaultImg());
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
