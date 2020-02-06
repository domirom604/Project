#include "Game.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sstream>
using namespace sf;
using namespace std;

Game::Game(float weight , float height )
{

	back.setPosition(422, 7);
	score.setPosition(7, 7);
	score_Nr.setPosition(126, 7);
	gameOver.setPosition(7, 150);
	for (int i = 0; i < 20; i++)
	{
		platform[i].x = rand() % 532;
		platform[i].y = (rand() % 730) + 150;
	}
}


void Game::draw(sf::RenderWindow &window1, angry_bird1* koko, Bonus* cor) {
	window1.draw(back);
	window1.draw(score);

	Texture t3;
	t3.loadFromFile("images/Platform1.png");
	Sprite Platform(t3);

	Texture t4;
	t4.loadFromFile("images/Doodle.png");
	Sprite Doodle(t4);

	Texture t5;
	t5.loadFromFile("images/Doodle2.png");
	Sprite Doodle2(t5);

	Texture t6;
	t6.loadFromFile("images/weapon.png");
	Sprite wand(t6);

	Texture t7;
	t7.loadFromFile("images/type_A.png");
	Sprite explosion(t7);


	for (int i = 0; i < 20; i++)
	{
		Platform.setPosition(platform[i].x, platform[i].y);
		window1.draw(Platform);
	}

	
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		x += 3;
	}
	if (Keyboard::isKeyPressed(Keyboard::A)) x -= 3;
	dy += 0.2;
	y += dy;

	
	if (y > 700) dy = -15;
	if (y < height_jump)
	{

		for (int i = 0; i < 20; i++)
		{
			y = height_jump;
			platform[i].y = platform[i].y - dy;
			if (platform[i].y > 730)
			{
				Score++;
				platform[i].y = 50;
				platform[i].x = rand() % 532;
			}
		}
	}

	for (int i = 0; i < 20; i++)
	{
		if ((x + 50 > platform[i].x) && (x + 20 < platform[i].x + 68)
			&& (y + 70 > platform[i].y) && (y + 70 < platform[i].y + 14) && (dy > 0))
		{
			dy = -10;
		}
	}
	Doodle.setPosition(x, y);
	Doodle2.setPosition(x, y);

	xx = x + 65;
	yy = y - 55;
	explosion.setPosition(xx, yy);
	wand.setPosition(xx, yy + 15);


	Frame += animSpeed;
	if (Frame > framecount) Frame -= framecount;
	explosion.setTextureRect(IntRect(int(Frame) * 50, 0, 50, 50));
	//cout << ycor->y_coordinate << endl;
	cor->y_coordinate = platform[15].y - 45;
	cor->x_coordinate = platform[15].x - 45;
	if (Keyboard::isKeyPressed(Keyboard::Space))
	{

		window1.draw(Doodle2);

		window1.draw(wand);
		window1.draw(explosion);

		cout << koko->y << endl;
		cout << yy << endl;
		if (koko->y + 40 == yy)
		{
			koko->y = 1200;
			Score += 100;
			koko->hp = 3;
			//x = (rand() % 400) + 80;
		}
	}

	
	

	else
	{

		window1.draw(Doodle);
	}

	if (cor->y_coordinate == y)
	{
		dy = -20;
		cor->y_coordinate = 750;

	}

	std::stringstream ss;
	ss << Score;
	score_Nr.setString(ss.str());
	window1.draw(score_Nr);

	score_var = Score;
	int z = 0;
	if (y > 690)
	{

		Doodle.setPosition(x, y);
		dy = 0;
		window1.draw(gameOver);
		savescore();

	}

	if (y == koko->y + 40)
	{

		y = 699;
		Doodle.setPosition(x, y);
		dy = 0;
		window1.draw(gameOver);
		savescore();

	}
}

void Game::savescore()
{
	//string line; 
	ofstream file;

	file.open("C:/Users/Szymon/Desktop/sfmlCP3/wyniki.txt", ios::out | ios::trunc);
	if (file.good() == true)
	{

		file.flush();
		cout << endl;
		file << score_var << endl;
		file.close();
	}
}
