#pragma once
#include<SFML\Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
using namespace sf;
using namespace std;


class Bonus 
{
public:
	float x_coordinate = 0;
	float y_coordinate = 50;
	void drawposition();
	sf::Clock spaw_nclock;
	sf::Time Time_spawn;
	void show_Bonus(sf::RenderWindow &window1, Sprite boost);
	int blockade=0;
	int dy=0;
	float dx = 0;
	Bonus(float weight = 532, float height = 850);
};

