#pragma once
#include "Menu1.h"
#include "Game.h"
#include <list>
using namespace sf;
using namespace std;

class Save1 :public Menu1, public Game
{
public:
	void draw(sf::RenderWindow &window1);
	int pos_y = 100;
	list<pair<int, string>> list;
	string number[11];
	string name[10];
	int number1[11];
	//string s = "";
	string newline = "\n";
	void read();
	void read_list(sf::RenderWindow &window1, string s);
	void save_list();
	Save1(float weight = 532, float height = 850);

};

