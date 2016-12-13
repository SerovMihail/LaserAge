#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list> 
#include <algorithm> 
#include "GameObject.h"
#include "TextureManager.h"
using namespace sf;
using namespace std;

Entity::Entity(TextureManager & tm, float X, float Y, int HEALTH) {
	x = X; y = Y;  moveTimer = 0; 
	speed = 0; health = HEALTH;
	//iAmAlive = true; 
	
	spriteHeight = sprite.getTextureRect().height; // Высота спрайта
	spriteWidth = sprite.getTextureRect().width; // Ширина спрайта	
	
}

void Entity::update(float time) {

}



	
