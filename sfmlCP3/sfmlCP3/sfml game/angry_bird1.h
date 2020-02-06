#pragma once
#include<SFML\Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
using namespace sf;
using namespace std;


class angry_bird1
{
public:
	
	int x = 0 ; 
	int y = 80;
	
	int *pointer;
	int hp = 2;
	float dy = 1;
	
	void show_bird(sf::RenderWindow &window1,Sprite bird);
	void drawpositionofbird();
	sf::Clock clock;
	sf::Clock clock1;
	sf::Time Time;
	sf::Time Time_after_died;
	int blockade = 0;
	angry_bird1(float weight = 532, float height = 850);
	
};

