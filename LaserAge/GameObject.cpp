#include "GameObject.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class TextureManager;
//// Базовый класс ///////
GameObject::GameObject(String Name, float X, float Y,  int W, int H, TextureManager & tm)
{	// Каждый объект в игре будет обладать рядом свойств. Основные, на которых будет основываться все объекты игры мы
	// отражаем в базовом классе IGameObject 
	// Загружаем изображение, которое соотвествует этому объекту

	//Ширина окна которая может быть изменена 
	windowWidth = W; windowHeight = H;

	//Каждый объект будет иметь координаты и ширину, высоту спрайта
	x = X; y = Y; 
	
	// А так же иметь скорость и скорость по координатам
	speed = 0; dx = 0; dy = 0;

	// Каждый объект существует, после его создания
	iAmAlive = true;
	name = Name; 

	// Исп в наследуемых классах
	//texture.loadFromImage(tm.getDefaultImg());
	//sprite.setTexture(texture);
	//sprite.setScale(0.5, 0.5); // масштаб
	//spriteHeight = sprite.getTextureRect().height; // Высота спрайта
	//spriteWidth = sprite.getTextureRect().width; // Ширина спрайта	

	sprite.setPosition(x, y);
}


void GameObject::update(float time)
{
	
}



GameObject::~GameObject()
{
}


