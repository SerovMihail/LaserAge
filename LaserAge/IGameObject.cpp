#include "Player.h"
#include "IBullet.h"
#include "IGameObject.h"
//#include <list>
//#include <iterator>
//#include <vector>
#include <SFML/Graphics.hpp>

//// Базовый класс ///////
IGameObject::IGameObject(Image &image, String Name, float X, float Y, int W, int H)
{	// Каждый объект в игре будет обладать рядом свойств. Основные, на которых будет основываться все объекты игры мы
	// отражаем в базовом классе IGameObject 
	// Загружаем изображение, которое соотвествует этому объекту
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setScale(0.5, 0.5); // масштаб


	//Ширина окна которая может быть изменена 
	windowWidth = W; windowHeight = H;
	//Каждый объект будет иметь координаты и ширину, высоту спрайта
	x = X; y = Y; 
	spriteHeight = sprite.getTextureRect().height; // Высота спрайта
	spriteWidth = sprite.getTextureRect().width; // Ширина спрайта	
	// А так же иметь скорость и скорость по координатам
	speed = 0; dx = 0; dy = 0;
	// Каждый объект существует, после его создания
	iAmAlive = true;
	
	
	
	name = Name; //Про запас

	sprite.setPosition(x, y);
}


void IGameObject::update(float time)
{

}



IGameObject::~IGameObject()
{
}


