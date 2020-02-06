#include "angry_bird1.h"
#include <iostream>
#include<SFML\Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
using namespace sf;
using namespace std;

angry_bird1::angry_bird1(float weight , float height )
{
}

void angry_bird1::drawpositionofbird()
{
	x = (rand() % 400) + 80;
}
void angry_bird1::show_bird(sf::RenderWindow &window1, Sprite bird)
{
next:
	try
	{
		if (hp > 3)
		{
			throw 2;
		}
	}
	catch (int e)
	{
		cout << "Error: " << e << endl;
	}
	if (hp == 2)
	{
		if (blockade == 0)
		{
			drawpositionofbird();
			blockade = 1;
		}
		dy += 0.002;

		this->y += dy;
		this->pointer = &y;
		bird.setPosition(x, y);
		window1.draw(bird);

		if (y > 730)
		{
			Time = clock.getElapsedTime();

			if (Time.asSeconds() >= 20)
			{
				y = 0;
				dy = 1;
				clock.restart();
				blockade = 0;
				goto next;
			}
		}
	}
	else
	{

		Time_after_died = clock1.getElapsedTime();
		cout << Time_after_died.asSeconds() << endl;
		if (Time_after_died.asSeconds() >= 20)
		{
			y = 0;
			dy = 1;
			clock1.restart();
			hp = 2;
			blockade = 0;
			goto next;
		}
	}
}

