#include "GameManager.h"
#include <SFML/Graphics.hpp>
#include <iostream> 
#include <sstream>
#include "GameObject.h"
#include "Player.h"
//#include "Bullet.h"
#include "LaserBullet.h"
#include "MediumBullet.h"
#include "BigBullet.h"
//#include "Container.h"
#include "TextureManager.h"
#include "ContainerLife.h"
#include "ContainerBullet.h"
#include "Menu.h"
#include <list>
#include <iterator>
#include <ctime>
// ������ 
#include "Enyme1.h"
#include "hardEneme.h"
#include "easyEneme.h"
#include "normalEneme.h"
#include "EnemyBullet.h"

using namespace sf;

GameManager::GameManager()
{
	widthWindow = 1000; // ������ ������
	heightWindow = 500; // ������ ������
	gameTime = 0; // ����� � ����
	spawnTime = 0.0; // ������ ������
	fpsTime = 0.0; // ������ ��� ������� � �������������� ����������
	level = 1; // �������� � ������� ������ 
	
}

TextureManager tm(1000, 500);
Player p("Player", (1000 / 2), (500 * 0.8), 1000, 500, tm, 100);
bool GameManager::play(int level) 
{
	//TextureManager tm(1000, 500); // ����� �� ���?)
	
	RenderWindow window(VideoMode(widthWindow, heightWindow), "LaserAge");

	//Player p("Player", (widthWindow / 2), (heightWindow * 0.8), widthWindow, heightWindow, tm, 100);
	
	selectLvl(level);


	// ������������� �������
	//TextureManager tm(widthWindow, heightWindow); // ������������� �������� � ������ ������ �����������	

	if (level == 1) {
		
		Menu m(window, widthWindow, heightWindow, tm);
		
	}
	
	
	

	
	Event event;
	while (window.isOpen())
	{		
		while (p.getIAmAlive() == true) {
			
			tickTime();

			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
				if (event.key.code == sf::Keyboard::Space)
				{
					selectWeapon(p.getBulletLvl(), tm, p); // ���������: ������� ���� - ���������� ��� �����. �� - ������ ���. � - ��� ���������			

				}				
			}

			window.clear();

			window.draw(tm.getBackgroundTexture()); // ������ ���

			runContainer(spawnTime, tm); // ��������� ����������

			 // ��������� ��, ������������ ������������
			update(p, tm);
			// ����
			for (it = bullet.begin(); it != bullet.end(); it++) {
				window.draw((*it)->getSprite()); //������ entities ������� (������ ��� ������ �����)
			}
			//������
			for (bt = bonus.begin(); bt != bonus.end(); bt++) {
				window.draw((*bt)->getSprite()); //������ entities ������� (������ ��� ������ �����)
			}
			//�����
			for (et = entities.begin(); et != entities.end(); et++) {				
				window.draw((*et)->getSprite());
			}

			for (ebt = ebullet.begin(); ebt != ebullet.end(); ebt++) {
				window.draw((*ebt)->getSprite()); //������ entities ������� (������ ��� ������ �����)
			}

			// ��������� ��������� ������ � ������ ���
			
			window.draw(p.getSprite());

			// ������������� ���������� �� ������ � ������� �
			tm.setText(p);
			window.draw(tm.getText());


			window.display();

			/*std::cout << fpsTime << "\n";
			std::cout << gameTime << "\n";
			std::cout << spawnTime << "\n";*/
			//std::cout << spawnTime << "\n";
			
			if (entities.empty()) {
				if (level <= 2) { level++; return true; }
				else {
					p.setIAmAlive(false);
					p.setWin(true);
				}
			}
			
		}

		window.clear();
		if (p.getWin() == true ) { window.draw(tm.getWinText()); }
		else { window.draw(tm.getTextGameOver()); }		
		window.display();


		while (window.pollEvent(event))
		{
			if (event.key.code == sf::Keyboard::Escape) { window.close(); }				
			if (event.key.code == sf::Keyboard::Space)
			{
				// ���������� �������� � ��������� ��������� � ������� ������ ������, ����
				p.setIAmAlive(true);
				p.setWin(false);
				entities.clear();
				ebullet.clear();
				bullet.clear();
				//p.~Player();
				Player p("Player", (widthWindow / 2), (heightWindow * 0.8), widthWindow, heightWindow, tm, 100);
				gameRunning(1);
			}
		}
		
	}
	return 0;
}



void GameManager::update(Player & p, TextureManager & tm) {	
	//////// �����. ��������� ��������� � ������ �� ����� �� ����� ///
	p.update(fpsTime);
	/////////////////////////////////////////////////////////////

	/////// ���� ������. �� ����� �� ������� ������ + ������������ � ������� ////////////
	next = false;
	
	for (it = bullet.begin(); it != bullet.end(); )
	{
		next = true;
			
		if (((*it)->getSprite().getPosition().y) < 0) {
			it = bullet.erase(it);			
			break;
		}

		for (et = entities.begin(); et != entities.end(); ) {
			//Enyme *e = *et;
			if ((*it)->getRect().intersects((*et)->getRect()))
			{
				p.addScore(100);
				//std::cout << "BAX";
				et = entities.erase(et);
				//delete e;

				it = bullet.erase(it);
				next = false;
				//delete b;
				break;
			}
			else {
				et++;

			}
		}

		if (next == true) {
			(*it)->update(fpsTime);
			it++;

		}


	}
	////////////////////////////////////////////////////


	/////// ������. �� ����� �� ������� ������ � ����������� � ������� //////////
	for (bt = bonus.begin(); bt != bonus.end();)
	{
		//Container *c = *bt;

		if ((*bt)->getRect().intersects(p.getRect())) {
			if (((*bt)->getName()) == "Life") {
				p.addLife();
				bt = bonus.erase(bt);
				//delete c;
				break;
			}
			if (((*bt)->getName()) == "Bullet") {
					
				if ((p.getBulletLvl()) <= 2) { 
					p.updateBullets(p.getBulletLvl()); 
					bt = bonus.erase(bt);
					//delete c;
					break;
				}
			}
		}

				
		if (((*bt)->getSprite().getPosition().y) >  heightWindow ) {
			bt = bonus.erase(bt);
			//delete c;
			break;
		}
		else {
			(*bt)->update(fpsTime);
			bt++;
		}

	}	
	///////////////////////////////////////////////////////

	/////// ���� ������. �� ��������� �� ������ + ��������� ������������. ///////////
	for (ebt = ebullet.begin(); ebt != ebullet.end(); )
	{
		//Bullet *ebm = *ebt;

		if ((*ebt)->getRect().intersects(p.getRect())) {
			p.damage((*ebt)->makeDamage());
			ebt = ebullet.erase(ebt);
			//delete ebm;			
			break;			
		}	
		if (((*ebt)->getSprite().getPosition().y) > heightWindow) {
			ebt = ebullet.erase(ebt);
			//delete ebm;
		}
		else {
			(*ebt)->update(fpsTime);
			ebt++;
		}
	}

	
	////////////////////////////////////////////////////
			
	////// �����. �� ���������� //////
	for (et = entities.begin(); et != entities.end(); et++) {
		
		(*et)->dv();
		if ((spawnTime > 2000 && spawnTime < 2010) || (spawnTime > 5000 && spawnTime < 5010) || (spawnTime > 8000 && spawnTime < 8010)) {
			ebullet.push_back(new EnemyBullet("enemyLaser", (*et)->getX(), (*et)->getY(), widthWindow, heightWindow, tm, 0, -1));
		}

	}
	////////////////////////////

}

void GameManager::tickTime() {
	/////////////////////// ������ �� �������� //////////////////////////////
	fpsTime = clock.getElapsedTime().asMicroseconds(); //��� �������������� ����
	gameTime = gameTimeClock.getElapsedTime().asSeconds(); // �������� ����� ������ � ����
	spawnTime = spawnTimeClock.getElapsedTime().asMilliseconds();
	clock.restart(); //������������� �����
	fpsTime = fpsTime / 800; // ��� ������ ��������, ��� ������� �������� ����	

	srand(time(0));// �������������� ������������
}

void GameManager::runContainer(float spawntime, TextureManager & tm) {
	// ������
	if (spawnTime > 8000 && spawnTime < 8010)  {
		bonus.push_back(new ContainerBullet("Bullet", rand() % widthWindow, 0, widthWindow, heightWindow, tm));

	}
	if (spawnTime > 4000 && spawnTime < 4010) {
		bonus.push_back(new ContainerLife("Life", rand() % widthWindow, 0, widthWindow, heightWindow, tm));

	}

	if (spawnTime > 10000) {
		spawnTimeClock.restart();
	}
}

void GameManager::selectWeapon(int weaponLvl, TextureManager & tm, Player & p) {
	if (weaponLvl == 1) { bullet.push_back(new LaserBullet("LaserBullet", p.getX(/*p*/) + (p.getSpriteWidth() / 4), p.getY(/*p*/), widthWindow, heightWindow, tm, 0, 2 )); }
	if (weaponLvl == 2) { bullet.push_back(new MediumBullet("MediumBullet", p.getX(/*p*/) + (p.getSpriteWidth() / 4), p.getY(/*p*/), widthWindow, heightWindow, tm, 0, 2)); }
	if (weaponLvl == 3) { bullet.push_back(new BigBullet("BigBullet", p.getX(/*p*/) + (p.getSpriteWidth() / 4), p.getY(/*p*/), widthWindow, heightWindow, tm, 0, 2)); }
}

void GameManager::selectLvl(int lvl)
{
	float x, y;
	x = 100;
	y = 50;

	
	if (lvl == 1) {
		/*Image image;
		image.loadFromFile("images/space1.png");*/

		while (x < 900) {
			entities.push_back(new Eneme1("EasyEnemy", x, y, widthWindow, heightWindow, tm));
			x = x + 100;
		}
	}

	if (lvl == 2) {
		/*Image image;
		image.loadFromFile("images/space2.png");*/
		while (x < 900) {
			entities.push_back(new normalEneme("NormalEnemy", x, y, widthWindow, heightWindow, tm));
			x = x + 80;
		}

	}
	if (lvl == 3) {
		/*Image image;
		image.loadFromFile("images/space3.png");*/
		while (x < 900) {
			entities.push_back(new hardEneme("HardEnemy", x, y, widthWindow, heightWindow, tm));
			x = x + 80;
		}
	}
}

void GameManager::startNewLvl() {
	level++;
}

void GameManager::gameRunning(int Level) {//�-��� ������������� ���� , ���� ��� ����������
	level = Level;
	if (play(level)) { level++;  gameRunning(level); }//��������� � ������ ������ ������ ����
}




GameManager::~GameManager()
{
}



