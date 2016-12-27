#include "GameManager.h"
#include <SFML/Audio.hpp>

int main()
{
	GameManager laserAge(1000, 500);

	sf::Music music;
	music.openFromFile("images/8bit.ogg");
	music.play();
	music.setLoop(true);

	int startLvl = 1;
	laserAge.gameRunning(startLvl);	

	return 0;
}
