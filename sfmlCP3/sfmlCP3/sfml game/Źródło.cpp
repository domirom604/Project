#include<SFML\Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <string>
#include <list>
#include <cstddef>
#include <algorithm>
#include <utility>
#include <windows.h>
#include "Menu1.h"
#include "angry_bird1.h"
#include "Game.h"
#include "Save1.h"
#include "Options.h"
//#include "Bonus.h"

using namespace sf;
using namespace std;


int a = 0;
string s = "";


void mousereaction(Event e , Menu1 &exit, sf::RenderWindow &window)
{

	if (e.type == sf::Event::MouseMoved)
	{
		cout << "new mouse x: " << e.mouseMove.x << endl;
		cout << "new mouse y: " << e.mouseMove.y << endl;
		if (e.mouseMove.x >= 835 && e.mouseMove.x <= 904 && e.mouseMove.y >= 550 && e.mouseMove.y <= 580)
		{
			exit.exxit.setFillColor(sf::Color::Red);
			
		}
		else
		{
			exit.exxit.setFillColor(sf::Color::Black);

		}

		if (e.mouseMove.x >= 635 && e.mouseMove.x <= 740 && e.mouseMove.y >= 406 && e.mouseMove.y <= 433)
		{
			exit.start.setFillColor(sf::Color::Red);

		}
		else
		{
			exit.start.setFillColor(sf::Color::Black);

		}

		if (e.mouseMove.x >= 972 && e.mouseMove.x <= 1106 && e.mouseMove.y >= 311 && e.mouseMove.y <= 348)
		{
			exit.options.setFillColor(sf::Color::Red);

		}
		else
		{
			exit.options.setFillColor(sf::Color::Black);

		}

		if (e.mouseMove.x >= 140 && e.mouseMove.x <= 240 && e.mouseMove.y >= 610 && e.mouseMove.y <= 652)
		{
			exit.score.setFillColor(sf::Color::Red);

		}
		else
		{
			exit.score.setFillColor(sf::Color::Black);

		}

	}
	if (e.mouseButton.x >= 835 && e.mouseButton.x <= 904 && e.mouseButton.y >= 550 && e.mouseButton.y <= 580)
	{
		a = 1;
		window.close();	
	}
	

	if (e.mouseButton.x >= 635 && e.mouseButton.x <= 740 && e.mouseButton.y >= 406 && e.mouseButton.y <= 433)
	{
		a = 2;
		window.close();
	}
	if (e.mouseButton.x >= 140 && e.mouseButton.x <= 240 && e.mouseButton.y >= 610 && e.mouseButton.y <= 652)
	{
		a = 3;
		window.close();
	}

	if (e.mouseButton.x >= 972 && e.mouseButton.x <= 1106 && e.mouseButton.y >= 311 && e.mouseButton.y <= 348)
	{
		a = 5;
		window.close();

	}

}

void mouseback(Event game, Menu1 &back, sf::RenderWindow &window1)
{
	if (game.type == sf::Event::MouseMoved)
	{
		cout << "new mouse x: " << game.mouseMove.x << endl;
		cout << "new mouse y: " << game.mouseMove.y << endl;
		if (game.mouseMove.x >= 424 && game.mouseMove.x <= 508 && game.mouseMove.y >= 18 && game.mouseMove.y <= 46)
		{
			back.back.setFillColor(sf::Color::Red);
		}
		else
		{
			back.back.setFillColor(sf::Color::Black);
		}	
	}
	if (game.mouseButton.x >= 424 && game.mouseButton.x <= 508 && game.mouseButton.y >= 18 && game.mouseButton.y <= 46)
	{
		
		window1.close();
		
	}
}

	int main()
	{
	 next:
	
		
		a = 0;
			
		RenderWindow window(VideoMode(1280,720), "MENU");
		//
		Vector2f mousePosition = Vector2f(Mouse::getPosition(window));
		
		
		Texture t1;
		t1.loadFromFile("images/tlo.png");
		
		Sprite background(t1);
		Texture t2;
		t2.loadFromFile("images/tlo1.png");
		Sprite background1(t2);
		

		Texture t22;
		t22.loadFromFile("images/bird1.png");
		Sprite enemy(t22);

		Texture t23;
		t23.loadFromFile("images/buty.png");
		Sprite boost(t23);

		Menu1 start(window.getSize().x, window.getSize().y);
		Menu1 options(window.getSize().x, window.getSize().y);
		Menu1 exit(window.getSize().x, window.getSize().y);
		

		sf::Font font;
		font.loadFromFile("arial.ttf");
		sf::String playerInput;
		sf::Text text;
		sf::Font font1;
		font1.loadFromFile("game_over.ttf");
		text.setFont(font1);
		text.setCharacterSize(90);
		text.setPosition(85, 250);
		text.setFillColor(sf::Color::Black);

		
		sf::Text entername;
		entername.setFont(font1);
		entername.setPosition(85, 150);
		entername.setFillColor(sf::Color::Blue);
		entername.setString("Enter your name: ");
		entername.setCharacterSize(110);


		

		

		while (window.isOpen())
		{
			Event e;
			
			while (window.pollEvent(e))
			{
				mousereaction(e, exit, window);
				
			}
			
			window.clear();
			window.draw(background);
			start.draw(window);
			options.draw(window);
			exit.draw(window);
			window.display();
		}
		
		if (a==1)
		{
			return 0;
		}
		if (a == 2)
		{
			cout << a << endl;
			RenderWindow window1(VideoMode(532, 850), "GAME");
			Vector2f mousePosition1 = Vector2f(Mouse::getPosition(window1));
			Game back(window1.getSize().x, window1.getSize().y );
			Menu1 back1(window1.getSize().x, window1.getSize().y);
			
			list<char> listofchar;
			//char znak;
			while (window1.isOpen())
			{
				Event game;
				while (window1.pollEvent(game))
				{
					
					mouseback(game, back1, window1);


					if (game.type == sf::Event::TextEntered)
					{


						try
						{

							if (game.text.unicode >= 32 && game.text.unicode <= 126) {
								playerInput += (char)game.text.unicode;

								listofchar.push_back((char)game.text.unicode);
							}

							if (game.text.unicode >= 33 && game.text.unicode <= 47)
							{
								throw 32;
							}
						}
						catch(int e)
						{

							entername.setString("Exeption!!!: ");
							
						}

					  if (game.text.unicode == 8 && playerInput.getSize() > 0)
							playerInput.erase(playerInput.getSize() - 1, 1);
						text.setString(playerInput);
						if (game.text.unicode == 13)
						{
							window1.close();
							int aa = 0;
							char * tab = new char[aa];
							int i = 0;
							for (list<char>::iterator iter = listofchar.begin(); iter != listofchar.end(); iter++)
							{
								cout << *iter;
								tab[i] = *iter;
								cout << endl;
								i++;
								aa++;
							}
							
							
							for (int i = 0; i < aa; i++)
							{
								s = s + tab[i];
							}
							cout << s;
							//delete [] tab;
							goto game;
						}
					}
					

					

				}
				
				window1.display();
				window1.draw(background1);
				window1.draw(entername);
				window1.draw(text);
				
				
				//back.draw(window1);
			}
			
			Save1 cc;
			cc.read();
			//cc.read_list();
			goto next;
		}
		if (a == 4)
		{
			game:
			cout << a << endl;
			RenderWindow window1(VideoMode(532, 850), "GAME");
			Vector2f mousePosition1 = Vector2f(Mouse::getPosition(window1));
			Game back(window1.getSize().x, window1.getSize().y);
			Menu1 back1(window1.getSize().x, window1.getSize().y);
			angry_bird1 a(window1.getSize().x, window1.getSize().y);
			Bonus bonus(window1.getSize().x, window1.getSize().y);
			
			
			
			

			while (window1.isOpen())
			{
				Event game;



				while (window1.pollEvent(game))
				{
					
					mouseback(game, back1, window1);
					
					
				}
				
				
				//int blokada = 0;
				
				Game kk;

				a.show_bird(window1, enemy);

				
				bonus.show_Bonus(window1,boost);

				window1.display();
				window1.draw(background1);
				
				back.draw(window1,&a, &bonus);
				
					
			}

			Save1 cc;
			cc.read();
			//cc.read_list();
			goto next;
		}
		if (a == 3)
		{
			RenderWindow window1(VideoMode(532, 850), "SCORE");
			Vector2f mousePosition1 = Vector2f(Mouse::getPosition(window1));
			Save1 back(window1.getSize().x, window1.getSize().y);
			Menu1 back1(window1.getSize().x, window1.getSize().y);
			while (window1.isOpen())
			{
				Event game;
				while (window1.pollEvent(game))
				{
					mouseback(game, back1, window1);
				}

				back.draw(window1);
				window1.display();
				window1.draw(background1);
				Save1 aa;
				aa.read_list(window1,s);
			}

			goto next;
		}


		if (a == 5)
		{
			RenderWindow window1(VideoMode(532, 850), "OPTIONS");
			Vector2f mousePosition1 = Vector2f(Mouse::getPosition(window1));
			Options back(window1.getSize().x, window1.getSize().y);
			Menu1 back1(window1.getSize().x, window1.getSize().y);
			while (window1.isOpen())
			{
				Event game;
				while (window1.pollEvent(game))
				{
					mouseback(game, back1, window1);
				}

				back.draw_back(window1);
				window1.display();
				window1.draw(background1);
				
				
			}

			goto next;
		}

		return 0;
	}
	
	