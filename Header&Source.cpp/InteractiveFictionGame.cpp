/*
	Zachary Hopping
	10-27-2020
	Interactive Fiction
	Create an interactive fiction game/story using more than one function our code must do something and be interactive
*/

#include "InteractiveFicHeader.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//Main FUnction
int main()
{
	string game = gameExplainfunc("Hi");
	cout << game << endl;
	cout << "Are you ready to play?" << endl;
	cout << "How long can you survive" << endl;
	string name = nameFunc("Please enter your name: ");
	cout << name << endl;
	cout << "[Y]es" << endl;
	cout << "[N]o" << endl;
	char input;
	cin >> input;
	if (input == 'Y' || input == 'y' || input == 'Yes' || input == 'yes')
	{
		int userOption;
		userOption = story1(1);
	}
	else
	{
		return 0;
	}

}
