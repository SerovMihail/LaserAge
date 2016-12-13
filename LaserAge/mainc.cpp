#include "Entity.h"
#include "normalEneme.h"
#include "easyEneme.h"
#include "Enyme1.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list> 
#include <algorithm> 
#include "hardEneme.h"

int main() {
	int lvl;
	
	sf::Clock clock;
	lvl = 1;
	
	

	
	sf::RenderWindow window(sf::VideoMode(1000, 500), "Enyme");
	float time = 0;
	while (window.isOpen())
	{
		window.clear();
		
		time = clock.getElapsedTime().asSeconds();
		clock.restart();
		
	
	
		window.display();
	}
}