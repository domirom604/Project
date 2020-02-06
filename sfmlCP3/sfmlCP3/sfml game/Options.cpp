#include "Options.h"

using namespace sf;
using namespace std;


Options::Options(float weight, float height)
{
	Menu1::back.setPosition(422, 7);
	
}

void Options::draw_back(sf::RenderWindow &window1)
{
	window1.draw(Menu1::back);
}


