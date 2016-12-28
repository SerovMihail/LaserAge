#include "GameObject.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class TxtureManager;
//// Базовый класс ///////
GameObject::GameObject(String Name, float X, float Y,  int W, int H)
{	// Каждый объект в игре будет обладать рядом свойств. Основные, на которых будет основываться все объекты игры мы
	// отражаем в базовом классе GameObject 
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
	//txture.loadFromImage(tm.di);
	//sprite.setTxture(txture);
	//sprite.setScale(0.5, 0.5); // масштаб

	//spriteHeight = sprite.getTxtureRect().height; // Высота спрайта
	//spriteWidth = sprite.getTxtureRect().width; // Ширина спрайта	

	sprite.setPosition(x, y);
}


void GameObject::update(float time)
{
	
}



GameObject::~GameObject()
{
}


