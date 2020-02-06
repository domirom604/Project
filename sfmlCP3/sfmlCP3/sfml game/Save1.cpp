#include "Save1.h"
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>

using namespace sf;
using namespace std;


Save1::Save1(float weight , float height )
{

	Menu1::back.setPosition(422, 7);
	Menu1::highscore.setPosition(142, 15);
	Menu1::numbers1.setPosition(100, 100);
	Menu1::numbers2.setPosition(300, 100);
}
void Save1::read()
{


}

void Save1::read_list(sf::RenderWindow &window1, string s) {

	stringstream sss;
	stringstream sss1;
	ifstream file("C:/Users/Szymon/Desktop/sfmlCP3/plik.txt");
	int counter = 1;
	string line;
	int ii = 0;
	int j = 0;
	while (!file.eof()) { // the place where program calculate how many lines of results have
		getline(file, line);


		if (counter % 2 == 0)
		{

			name[ii] = line;
			ii++;
		}
		else
		{

			number[j] = line;
			j++;
		}
		counter++;
	}

	file.close();

	number1[11];


	for (int i = 0; i < 10; i++)
	{
		number1[i] = atoi(number[i].c_str());
	}


	ifstream filee("C:/Users/Szymon/Desktop/sfmlCP3/wyniki.txt");
	//string line;
	int reading;
	int tab[1];
	int score = 0;
	while (filee >> reading) {


		cout << reading;
		tab[0] = reading;
	}

	number1[9] = tab[0];


	name[9] = s;

	for (int i = 0; i < 10; i++)
	{

		list.push_back(make_pair(number1[i], name[i]));

	}


	list.sort();
	list.reverse();
	//lista.pop_back();
	save_list();


	size_t size = list.size();
	for (auto item : list) {
		cout << item.first << " " << item.second << endl;
		sss << item.first;
		Menu1::numbers1.setString(sss.str());
		window1.draw(Menu1::numbers1);
		sss << newline;
		Menu1::numbers1.setString(sss.str());
		window1.draw(Menu1::numbers1);


	}
	for (auto item : list) {
		//cout << item.second;
		sss1 << item.second;
		Menu1::numbers2.setString(sss1.str());
		window1.draw(Menu1::numbers2);
		sss1 << newline;
		Menu1::numbers2.setString(sss1.str());
		window1.draw(Menu1::numbers2);
	}

}
void Save1::save_list()
{

	string line;
	ofstream file;

	file.open("C:/Users/Szymon/Desktop/sfmlCP3/plik1.txt", ios::out | ios::trunc);
	if (file.good() == true)
	{
		file.flush();
		for (auto item : list) {

			file << item.first << endl;
			file << item.second << endl;
		}

		file.close();
	}

}
void Save1::draw(sf::RenderWindow &window1) {
	window1.draw(Menu1::back);
	window1.draw(Menu1::highscore);

	std::stringstream ss;

	for (int i = 1; i < 11; i++)
	{

		Menu1::numbers.setPosition(42, 100);
		ss << i;
		Menu1::numbers.setString(ss.str());
		window1.draw(Menu1::numbers);
		ss << newline;
		Menu1::numbers.setString(ss.str());
		window1.draw(Menu1::numbers);
	}

}
