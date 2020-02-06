#pragma once
#include <iostream>
#include<SFML\Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "angry_bird1.h"
#include "Menu1.h"
#include "Bonus.h"


class Game :public Menu1, public angry_bird1, public Bonus
{
public:
	void draw(sf::RenderWindow &window1, angry_bird1* koko, Bonus* cor);
	int score_var;
	void savescore();
	float Frame = 0;
	float animSpeed = 0.4;
	int framecount = 20;
	struct point { int x, y; };
	point platform[20];
	Sprite Platform;
	int x = 100, y = 100, height_jump = 250;
	int xx = x;
	int yy = y;
	float dx = 0, dy = 0;
	
	Game(float weight = 532, float height = 850);


};

