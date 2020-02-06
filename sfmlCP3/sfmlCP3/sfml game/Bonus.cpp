#include "Bonus.h"
#include <iostream>
#include<SFML\Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
using namespace sf;
using namespace std;

Bonus::Bonus(float weight, float height)
{
}
void Bonus::drawposition()
{
	x_coordinate = (rand() % 400) + 80;
}

void Bonus::show_Bonus(sf::RenderWindow &window1, Sprite boost)
{
	if (blockade == 0)
	{
		drawposition();
		blockade = 1;
	}

	dy += 1;
	dx += 0.1;
	//y_coordinate +=dy;
	y_coordinate = y_coordinate + dy;
	dy = 0;
	dx = 0;
	
	boost.setPosition(x_coordinate, y_coordinate);
	window1.draw(boost);

}

