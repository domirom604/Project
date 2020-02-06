#include "angry_bird1.h"
#include "Menu1.h"
#include <iostream>
#include<SFML\Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;
using namespace std;

Menu1::Menu1(float weight , float height )
{
	myFont.loadFromFile("arial.ttf");
	game_Over.loadFromFile("game_over.ttf");

	start.setFont(myFont);
	start.setFillColor(sf::Color::Black);
	start.setString("Game");
	start.setCharacterSize(40);
	start.setPosition(633, 393);

	options.setFont(myFont);
	options.setFillColor(sf::Color::Black);
	options.setString("Options");
	options.setCharacterSize(40);
	options.setPosition(970, 300);

	exxit.setFont(myFont);
	exxit.setFillColor(sf::Color::Black);
	exxit.setString("Exit");
	exxit.setCharacterSize(40);
	exxit.setPosition(840, 540);

	back.setFont(myFont);
	back.setFillColor(sf::Color::Black);
	back.setString("Back");
	back.setCharacterSize(40);

	score.setFont(myFont);
	score.setFillColor(sf::Color::Black);
	score.setString("Score ");
	score.setCharacterSize(40);

	score_Nr.setFont(myFont);
	score_Nr.setFillColor(sf::Color::Black);
	score_Nr.setCharacterSize(40);


	gameOver.setFont(game_Over);
	gameOver.setFillColor(sf::Color::Black);
	gameOver.setString("GAME OVER!!!");
	gameOver.setCharacterSize(200);

	highscore.setFont(game_Over);
	highscore.setFillColor(sf::Color::Blue);
	highscore.setString("HIGH SCORE: ");
	highscore.setCharacterSize(110);


	numbers.setFont(game_Over);
	numbers.setFillColor(sf::Color::Blue);
	numbers.setCharacterSize(90);

	numbers1.setFont(game_Over);
	numbers1.setFillColor(sf::Color::Black);
	numbers1.setCharacterSize(90);

	numbers2.setFont(game_Over);
	numbers2.setFillColor(sf::Color::Black);
	numbers2.setCharacterSize(90);
}

void Menu1::draw(sf::RenderWindow &window) {
	window.draw(start);
	window.draw(options);
	window.draw(exxit);
	score.setPosition(140, 610);
	window.draw(score);
}






