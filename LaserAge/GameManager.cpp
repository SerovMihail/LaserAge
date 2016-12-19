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
#include "Enemy.h"
#include "HardEnemy.h"
#include "EasyEnemy.h"
#include "NormalEnemy.h"
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
	restartGame = false;
	maxLvl = 10; // ����� 3 ������
	ex = 0;
	ey = 0;
	
}



bool GameManager::play(int & Level)
{

	RenderWindow window(VideoMode(widthWindow, heightWindow), "LaserAge");

	Player static p("Player", (widthWindow / 2), (heightWindow * 0.8), widthWindow, heightWindow, 200);

	selectLvl(level); // �������� ���������� ��� ������ ������

	if (level == 1) { // ������ ��� ��������� �������� ������ ������������� ����� ����		
		Menu m(window, widthWindow, heightWindow);		
	}

	
	Event event;
	while (window.isOpen())
	{		
		while (p.getIAmAlive() == true) { // ���� ���� ������������ ���� ����� ��� ��� ���� ��� ����� ����			

			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
				if (event.key.code == sf::Keyboard::Space)
				{
					selectWeapon(p.getBulletLvl(), p); // ���������: ������� ���� - ���������� ��� �����. �� - ������ ���. � - ��� ���������			

				}	
				if (event.key.code == sf::Keyboard::Tab)
				{
					std::cout << level;
					bullet.clear();
					ebullet.clear();
					level++;
					return true; // �������� � gameRunning			

				}

				
			}

			tickTime(); // ��������� �����

			window.clear();			

			runContainer(spawnTime); // ��������� ����������

			 // ��������� ��, ������������ ������������
			update(p);
			// ������ ��
			draw(window, p);

			window.display();

			/*std::cout << fpsTime << "\n";
			std::cout << gameTime << "\n";
			std::cout << spawnTime << "\n";*/



			if (p.getIAmAlive() == false) {			// ���� ����� ���� 
				clearAllContainer();
				p.setWin(false);
				
			}
			
			if (entities.empty()) { // ���� ����� �����������
				if (level <= maxLvl) {  // ������� �� ��������� ������� �.� �� ��� ���� ��������
					bullet.clear();
					ebullet.clear();
					level++;
					std::cout << level << "\n";
					return true; // �������� � gameRunning
				}
				else { // �������� ��������� �������
					
					p.setIAmAlive(false);
					p.setWin(true);
				}					
			}
		}	

		

		// ���� ��� ������������ ����. �� ���� ������, ���� ��������. ������� ������ ������������
		while (window.pollEvent(event))
		{
			window.clear();

			if (p.getWin() == true) {
				window.draw(tm.getWinText());
			}
			else {
				window.draw(tm.getTextGameOver());
			}

			window.display();

			if (event.key.code == sf::Keyboard::Escape) { window.close(); }
			if (event.key.code == sf::Keyboard::E)
			{
				// ���������� �������� � ��������� ��������� � ������� ������ ������, ����
				p.setIAmAlive(true);
				p.setWin(false);
				p.newGame();
				clearAllContainer();

				restartGame = true;				
				return true; // ������������
				
			}
		}
	}

	return 0;
}

void GameManager::clearAllContainer() {
	ebullet.clear();
	bullet.clear();
	bonus.clear();
	entities.clear();
}



void GameManager::update(Player & p) {	
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
		
		(*et)->dv(fpsTime);
		if ((spawnTime > 2000 && spawnTime < 2005) || (spawnTime > 5000 && spawnTime < 5005) || (spawnTime > 8000 && spawnTime < 8005)) {
			ebullet.push_back(new EnemyBullet("enemyLaser", (*et)->getX(), (*et)->getY(), widthWindow, heightWindow));
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

void GameManager::runContainer(float spawntime) {
	// ������
	if (spawnTime == 5000)  {
		bonus.push_back(new ContainerBullet("Bullet", rand() % widthWindow, 0, widthWindow, heightWindow));

	}
	if (spawnTime == 10000) {
		bonus.push_back(new ContainerLife("Life", rand() % widthWindow, 0, widthWindow, heightWindow));

	}

	if (spawnTime > 10000) {
		spawnTimeClock.restart();
	}
}

void GameManager::selectWeapon(int weaponLvl, Player & p) {
	if (weaponLvl == 1) { bullet.push_back(new LaserBullet("LaserBullet", p.getX(/*p*/) + (p.getSpriteWidth() / 4), p.getY(/*p*/), widthWindow, heightWindow)); }
	if (weaponLvl == 2) { bullet.push_back(new MediumBullet("MediumBullet", p.getX(/*p*/) + (p.getSpriteWidth() / 4), p.getY(/*p*/), widthWindow, heightWindow)); }
	if (weaponLvl == 3) { bullet.push_back(new BigBullet("BigBullet", p.getX(/*p*/) + (p.getSpriteWidth() / 4), p.getY(/*p*/), widthWindow, heightWindow)); }
}

void GameManager::selectLvl(int lvl)
{
	
	

	
	if (lvl == 1) {
		ex = 70;
		ey = 50;

		

		while (ex < 700) {
			entities.push_back(new EasyEnemy("EasyEnemy", ex, ey, widthWindow, heightWindow));
			ex = ex + 100;
			std::cout << "ex: " << ex << "\n" << "ey: " << ey << "\n";
		}
		
		
	}

	if (lvl == 2) {
		ex = 70;
		ey = 50;

		while (ex < 800) {
			entities.push_back(new NormalEnemy("NormalEnemy",ex, ey, widthWindow, heightWindow));
			ex = ex + 100;
		}
		

	}
	if (lvl == 3) {

		ex = 70;
		ey = 50;
		
		while (ex < 800) {
			entities.push_back(new HardEnemy("HardEnemy", ex, ey, widthWindow, heightWindow));
			ex = ex + 100;
		}
		
	}
	if (lvl == 4) {

		ex = 70;
		ey = 50;
		
		while (ex < 800) {
			ey = 100;
			
			entities.push_back(new HardEnemy("HardEnemy", ex, ey, widthWindow, heightWindow));

			
			entities.push_back(new EasyEnemy("EasyEnemy", ex, ey, widthWindow, heightWindow));

			ey = 200;

			entities.push_back(new EasyEnemy("EasyEnemy", ex, ey, widthWindow, heightWindow));
			ex = ex + 100;
		}
		
	}
	if (lvl == 5) {
		
		ex = 70;
		ey = 50;

		while (ex < 800) {
			ey = 100;

			
			entities.push_back(new  HardEnemy("HardEnemy", ex, ey, widthWindow, heightWindow));

			
			entities.push_back(new NormalEnemy("NormalEnemy",ex, ey, widthWindow, heightWindow));


			
			entities.push_back(new EasyEnemy("EasyEnemy", ex, ey, widthWindow, heightWindow));

			ey = 200;

			entities.push_back(new EasyEnemy("EasyEnemy", ex, ey, widthWindow, heightWindow));
			ex = ex + 100;
		}
		
	}
	if (lvl == 6) {
		
		ex = 70;
		ey = 50;

		while (ex < 800) {
			ey = 100;

			
			entities.push_back(new  HardEnemy("HardEnemy", ex, ey, widthWindow, heightWindow));
			ey = 200;
			
			entities.push_back(new  HardEnemy("HardEnemy", ex, ey, widthWindow, heightWindow));

			
			entities.push_back(new NormalEnemy("NormalEnemy",ex, ey, widthWindow, heightWindow));
			ey = 100;

			
			entities.push_back(new EasyEnemy("EasyEnemy", ex, ey, widthWindow, heightWindow));

			ey = 200;

			entities.push_back(new EasyEnemy("EasyEnemy", ex, ey, widthWindow, heightWindow));
			ex = ex + 100;

		}
		
	}
	if (lvl == 7) {
		
		ex = 70;
		ey = 50;

		while (ex < 800) {
			ey = 100;

			
			entities.push_back(new  HardEnemy("HardEnemy", ex, ey, widthWindow, heightWindow));
			ey = 200;
			
			entities.push_back(new  HardEnemy("HardEnemy", ex, ey, widthWindow, heightWindow));

			
			entities.push_back(new NormalEnemy("NormalEnemy",ex, ey, widthWindow, heightWindow));
			ey = 100;
			
			entities.push_back(new NormalEnemy("NormalEnemy",ex, ey, widthWindow, heightWindow));


			
			entities.push_back(new EasyEnemy("EasyEnemy", ex, ey, widthWindow, heightWindow));

			ey = 200;

			entities.push_back(new EasyEnemy("EasyEnemy", ex, ey, widthWindow, heightWindow));
			ex = ex + 100;

		}
		
	}
	if (lvl == 8) {
		
		while (ex < 800) {
			ey = 80;

			
			entities.push_back(new  HardEnemy("HardEnemy", ex, ey, widthWindow, heightWindow));
			ey = 160;

			
			entities.push_back(new  HardEnemy("HardEnemy", ex, ey, widthWindow, heightWindow));
			ey = 240;
			
			entities.push_back(new  HardEnemy("HardEnemy", ex, ey, widthWindow, heightWindow));
			
			entities.push_back(new NormalEnemy("NormalEnemy",ex, ey, widthWindow, heightWindow));
			ey = 80;
			
			entities.push_back(new NormalEnemy("NormalEnemy",ex, ey, widthWindow, heightWindow));


			
			entities.push_back(new EasyEnemy("EasyEnemy", ex, ey, widthWindow, heightWindow));

			ey = 200;

			entities.push_back(new EasyEnemy("EasyEnemy", ex, ey, widthWindow, heightWindow));
			ex = ex + 100;

		}
		ex = 70;
		ey = 50;
	}
	if (lvl == 9) {
		
		while (ex < 800) {
			ey = 80;

			
			entities.push_back(new  HardEnemy("HardEnemy", ex, ey, widthWindow, heightWindow));
			ey = 160;

			
			entities.push_back(new  HardEnemy("HardEnemy", ex, ey, widthWindow, heightWindow));

			ey = 240;
			
			entities.push_back(new  HardEnemy("HardEnemy", ex, ey, widthWindow, heightWindow));

			
			entities.push_back(new NormalEnemy("NormalEnemy",ex, ey, widthWindow, heightWindow));

			ey = 80;
			
			entities.push_back(new NormalEnemy("NormalEnemy",ex, ey, widthWindow, heightWindow));

		
			entities.push_back(new EasyEnemy("EasyEnemy", ex, ey, widthWindow, heightWindow));

			ey = 160;
			
			entities.push_back(new EasyEnemy("EasyEnemy", ex, ey, widthWindow, heightWindow));
			ey = 240;

			entities.push_back(new EasyEnemy("EasyEnemy", ex, ey, widthWindow, heightWindow));
			ex = ex + 100;

		}
		ex = 70;
		ey = 50;
	}
	if (lvl == 10) {
	
		ex = 100;
		while (ex < 800) {

			ey = 70;

			
			entities.push_back(new EasyEnemy("EasyEnemy", ex, ey, widthWindow, heightWindow));
			
			entities.push_back(new NormalEnemy("NormalEnemy",ex, ey, widthWindow, heightWindow));
			ey = 160;
			
			entities.push_back(new NormalEnemy("NormalEnemy",ex, ey, widthWindow, heightWindow));
			
			entities.push_back(new  HardEnemy("HardEnemy", ex, ey, widthWindow, heightWindow));
			ex = ex + 100;
		}
		ex = 160;
		while (ex < 900) {

			ey = 200;

			
			entities.push_back(new EasyEnemy("EasyEnemy", ex, ey, widthWindow, heightWindow));
		
			entities.push_back(new NormalEnemy("NormalEnemy",ex, ey, widthWindow, heightWindow));
			
			entities.push_back(new  HardEnemy("HardEnemy", ex, ey, widthWindow, heightWindow));
			ex = ex + 100;
		}
		ex = 70;
		ey = 50;
	}
	if (lvl == 11) {
		
		ex = 100;
		while (ex < 800) {
			ey = 70;
			
			entities.push_back(new  HardEnemy("HardEnemy", ex, ey, widthWindow, heightWindow));
			
			entities.push_back(new NormalEnemy("NormalEnemy",ex, ey, widthWindow, heightWindow));
			ey = 140;
			
			entities.push_back(new  HardEnemy("HardEnemy", ex, ey, widthWindow, heightWindow));
			
			entities.push_back(new NormalEnemy("NormalEnemy",ex, ey, widthWindow, heightWindow));
			ey = 210;
			
			entities.push_back(new  HardEnemy("HardEnemy", ex, ey, widthWindow, heightWindow));
			
			entities.push_back(new NormalEnemy("NormalEnemy",ex, ey, widthWindow, heightWindow));
			ex = ex + 100;
		}
		ex = 70;
		ey = 50;
	}
}



void GameManager::gameRunning(int & Level) {//�-��� ������������� ���� , ���� ��� ����������
	
	if (play(Level)) // ���� �������� ���� �� "�������� �� ���� �������"
		//restartGame = false;
		if (!restartGame){ 			 
			gameRunning(level); //��������� � ������ ������ ������ ����}
		}
		else {			
			clearAllContainer();
			level = 1;
			restartGame = false;

			gameRunning(level);
		}
			
			
	
}

void GameManager::draw(RenderWindow & window, Player & p) {
	window.draw(tm.getBackgroundTexture()); // ������ ���

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

}




GameManager::~GameManager()
{
}



