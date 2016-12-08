#include <SFML/Graphics.hpp>
#include <iostream> 
#include <sstream>
#include "Player.h"
#include "IBullet.h"
#include "IGameObject.h"
#include "Container.h"
#include <list>
#include <iterator>
#include <vector>
#include <ctime>

using namespace sf;

//void menu(RenderWindow & window) {
//	Texture menuTexture1; /* menuTexture2, menuTexture3, aboutTexture, menuBackground;*/
//	menuTexture1.loadFromFile("images/111.png");
//	/*menuTexture2.loadFromFile("images/111.png");
//	menuTexture3.loadFromFile("images/111.png");
//	aboutTexture.loadFromFile("images/111.png");
//	menuBackground.loadFromFile("images/111.png");*/
//	Sprite menu1(menuTexture1);/*, menu2(menuTexture2), menu3(menuTexture3), about(aboutTexture), menuBg(menuBackground);*/
//	bool isMenu = 1;
//	int menuNum = 0;
//	menu1.setPosition(0, 0);
//	/*menu2.setPosition(100, 90);
//	menu3.setPosition(100, 150);
//	menuBg.setPosition(345, 0);*/
//
//	//////////////////////////////МЕНЮ///////////////////
//	while (isMenu)
//	{
//		menu1.setColor(Color::White);
//		/*menu2.setColor(Color::White);
//		menu3.setColor(Color::White);*/
//		menuNum = 0;
//		window.clear(Color(129, 181, 221));
//
//		if (IntRect(100, 30, 300, 50).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Blue); menuNum = 1; }
//		/*if (IntRect(100, 90, 300, 50).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Blue); menuNum = 2; }
//		if (IntRect(100, 150, 300, 50).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); menuNum = 3; }*/
//
//		if (Mouse::isButtonPressed(Mouse::Left))
//		{
//			if (menuNum == 1) isMenu = false;//если нажали первую кнопку, то выходим из меню 
//			/*if (menuNum == 2) { window.draw(about); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }
//			if (menuNum == 3) { window.close(); isMenu = false; }*/
//
//		}
//
//		/*window.draw(menuBg);*/
//		window.draw(menu1);
//		/*window.draw(menu2);
//		window.draw(menu3);*/
//
//		window.display();
//	}
//	////////////////////////////////////////////////////
//}

int main()
{	

	int widthWindow = 1000; // Ширина экрана
	int heightWindow = 500; // Высота экрана
	RenderWindow window(VideoMode(widthWindow, heightWindow), "LaserAge");
	//menu(window);//вызов меню
	

	Clock clock;	
	Clock gameTimeClock;//переменная игрового времени, будем здесь хранить время игры 
	Clock spawnTimeClock;//переменная игрового времени, будем здесь хранить время игры 
	int gameTime = 0;//объявили игровое время, инициализировали.
	float spawnTime = 0.0;

	/////////////////////// Свойства шрифта ////////////////////////
	Font font;//шрифт 
	font.loadFromFile("Bungee-Regular.ttf");//передаем нашему шрифту файл шрифта
	Text text("", font, 20);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
	text.setStyle(Text::Bold | Text::Underlined);//жирный и подче
	//text.setColor(sf::Color::Red);
			
	Image ship;
	ship.loadFromFile("images/greenPlayer.png");
	Player p(ship, "sprite", (widthWindow / 2), (heightWindow * 0.8), widthWindow, heightWindow, 100);

	// Загрузка картинок разных видов оружия
	Image laser;
	laser.loadFromFile("images/laserRed.png"); // 1 тип
	Image normalLaser;
	normalLaser.loadFromFile("images/normalLaser.png"); // 2 тип
	Image bigLaser;
	bigLaser.loadFromFile("images/bigLaser.png"); // 3 тип 
	std::list<IBullet*>  bullet;// список пуль
	std::list<IBullet*>::iterator it;//итератор чтобы проходить по эл-там списка

	Image ContainerLife;
	ContainerLife.loadFromFile("images/containerLife.png");
	Image ContainerBullet;
	ContainerBullet.loadFromFile("images/containerBullet.png");
	std::list<Container*>  bonus;//список бонусов
	std::list<Container*>::iterator et;//итератор чтобы проходить по эл-там списка
	
	
	

	while (window.isOpen()) // Пока окно открыто
	{
		
		srand(time(0)); // автоматическая рандомизация
		/////////////////////// Работа со временем //////////////////////////////
		float time = clock.getElapsedTime().asMicroseconds(); //Для быстродействия игры
		gameTime = gameTimeClock.getElapsedTime().asSeconds(); // Засекаем время игрока в игре
		spawnTime = spawnTimeClock.getElapsedTime().asMilliseconds();
		clock.restart(); //перезагружает время
		time = time / 600; // чем меньше делитель, тем быстрее скорость игры	
		
		
		////////////////////// Обработка прерывания ////////////////////////////////
		

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Space)
				{
					
					/// При каждом нажатии ПРОБЛЕА добавляем выстрел в координате корабля //
					if (p.getBulletLvl() == 1) {
						bullet.push_back(new IBullet(laser, "laser", p.getX(p) + (p.getSpriteWidth() / 4), p.getY(p), widthWindow, heightWindow, 1));
					}					
					if (p.getBulletLvl() == 2) {
						bullet.push_back(new IBullet(normalLaser, "normalLaser", p.getX(p) + (p.getSpriteWidth() / 4), p.getY(p), widthWindow, heightWindow, 2));
					}
					if (p.getBulletLvl() == 3) {
						bullet.push_back(new IBullet(bigLaser, "bigLaser", p.getX(p) + (p.getSpriteWidth() / 4), p.getY(p), widthWindow, heightWindow, 3));
					}
					
					
					
				}
			}
		}		

		
		

		if (spawnTime == 5000  ) {
			bonus.push_back(new Container(ContainerBullet, "Bullet", rand() % widthWindow, 0, widthWindow, heightWindow));
			
		}
		if (spawnTime == 10000) {
			bonus.push_back(new Container(ContainerLife, "Life", rand() % widthWindow, 0, widthWindow, heightWindow));
			
		}
		
		if (spawnTime > 10000) {
			spawnTimeClock.restart();
		}
	
	
		/////////////// Вызовы методов //////////////////
		
		
		window.clear(Color::Cyan); // Задний фон
		
		////////////////////////////////////////////////////////
		////// Обработка пуль ////////////////////////////////		
		//////////////////////////////////////////////////////
		for (it = bullet.begin(); it != bullet.end(); it++) {
			window.draw((*it)->getSprite()); //рисуем entities объекты (сейчас это только враги)
		}
		
		
		for (it = bullet.begin(); it != bullet.end();)
		{
			IBullet *b = *it;
			if (((*it)->getSprite().getPosition().y) < 0) {
				it = bullet.erase(it);
				delete b;
			}
			else {
				(*it)->update(time);
				it++;
			}

		}

		////////////////////////////////////////////////////////
		////// Обработка Игрока////////////////////////////////		
		//////////////////////////////////////////////////////

		p.update(time);
		window.draw(p.getSprite());

		////////////////////////////////////////////////////////
		////// Обработка контейнера "Жизнь" и "Пули" //////////		
		//////////////////////////////////////////////////////

		for (et = bonus.begin(); et != bonus.end(); et++) {		
			window.draw((*et)->getSprite()); //рисуем entities объекты (сейчас это только враги)
		}

		for (et = bonus.begin(); et != bonus.end();)
		{
			Container *c = *et;

			if ((*et)->getRect().intersects(p.getRect())) {
				if (((*et)->getName()) == "Life") {
					p.addLife();
					et = bonus.erase(et);
					delete c;
					break;
				}
				if (((*et)->getName()) == "Bullet") {
				
					if ((p.getBulletLvl()) <= 2) { 
						p.updateBullets(p.getBulletLvl()); 
						et = bonus.erase(et);
						delete c;
						break;
					}
				}
			}

			
			if (((*et)->getSprite().getPosition().y) > heightWindow ) {
				et = bonus.erase(et);
				delete c;
				break;
			}
			else {
				(*et)->update(time);
				et++;
			}

		}	

		
					
		// Вспомогательные значения по игре
		std::ostringstream playerHealthString, gameTimeString, playerLifeString, playerScoreString;     // объявили переменную здоровья и времени
		std::ostringstream xStr, yStr;
		
		// формируем строки
		xStr << p.getX(p);
		yStr << p.getY(p);
		playerHealthString << p.getHealth(p); 
		gameTimeString << spawnTime;// gameTime;
		playerLifeString << p.getLife(p);	
		playerScoreString << p.getScore(p); 
		text.setString("Score:" + playerScoreString.str()
			+ "\nHealth: " + playerHealthString.str() 
			+ "\nSeconds in game: " + gameTimeString.str()
			+ "\nLife: " + playerLifeString.str()
			+ "\nx: " + xStr.str() + "\ny: " + yStr.str());//задаем строку тексту и вызываем сформированную выше строку методом .str()

		text.setPosition(10, 10);//задаем позицию текста, центр камеры
		window.draw(text);//рисую этот текст

		

		window.display();	
		

		std::cout << gameTime << "\n"; 
	}

	return 0;
}