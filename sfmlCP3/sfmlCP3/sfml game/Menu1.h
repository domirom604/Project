#pragma once
#include<SFML\Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "angry_bird1.h"


using namespace sf;
using namespace std;

class Menu1
{

public:

	Menu1(float weight = 1280, float height = 720);
	void draw(sf::RenderWindow &window);
	int Score = 0;


	sf::Font myFont;
	sf::Font game_Over;
	sf::Text start;
	sf::Text options;
	sf::Text exxit;
	sf::Text back;
	sf::Text score;
	sf::Text score_Nr;
	sf::Text gameOver;
	sf::Text highscore;
	sf::Text numbers;
	sf::Text numbers1;
	sf::Text numbers2;

};

