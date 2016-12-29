#pragma once
#include "Enemy.h"
#include <SFML/Graphics.hpp>





using namespace sf;

class NormalEnemy:public Enemy
{
public:
	
	NormalEnemy(String Name, float X, float Y, int W, int H);

<<<<<<< HEAD
<<<<<<< HEAD
	void update(float time);

	
=======
	void update(int time, int width, int heigth);
>>>>>>> ea4659c3deeb2816fce64591e7c4c9d3f77abe89
=======
	void update(int time, int width, int heigth);
>>>>>>> origin/master
};

