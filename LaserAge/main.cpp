#include "GameManager.h"
#include <SFML/Audio.hpp>

int main()
{
	GameManager laserAge;
	sf::Music music;
	music.openFromFile("images/8bit.ogg");
	music.play();
	int startLvl = 1;
	laserAge.gameRunning(startLvl);	

	return 0;
}
