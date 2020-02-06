#pragma once
#include "Menu1.h"
using namespace sf;
using namespace std;

class Options :public Menu1
{
public:
	Options(float weight = 532, float height = 850);
	void draw_back(sf::RenderWindow &window1);
	
};

