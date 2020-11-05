/*
	Zachary Hopping
	10-27-2020
	Interactive Fiction
	Create an interactive fiction game/story using more than one function our code must do something and be interactive
*/

#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

string nameFunc(string Username);
int story1(int options);


int main()
{
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

string nameFunc(string Username)
{
	string name;
	cout << "Please enter your name: " << endl;
	cin >> name;
	cout << "Hello, are you ready to play ";
	return name;
}

int story1(int options)
{
	int option1;
	cout << "It is October 31st and you have been making an all day drive to visit your friends." << endl;
	cout << "It is late and you have been following the direction on your phone." << endl;
	cout << "Suddenly you hear a loud tremble, and you lose control of your car and hit the gaurd rail." << endl;
	cout << "After your inital state of being shocked passes, you gather your thoughts and:" << endl;
	cout << "1: Get out of your car and assess the damage." << endl;
	cout << "2: Check your phone." << endl;
	cout << "3: Quit Game! :(" << endl;
	cin >> option1;
	if (option1 == 1)
	{
		int option2;
		cout << "You get out of your car and see your front end is smashed and you decide you wont be driving anywhere tonight." << endl;
		cout << "1: Check your phone." << endl;
		cout << "2: Open your Trunk." << endl;
		cin >> option2;
		if (option2 == 1)
		{
			int option2b;
			cout << "You check your phone and have no reception." << endl;
			cout << "1: You can wonder around hoping to find a signal to make a phone call." << endl;
			cout << "2: Sit and wait for someone to drive by." << endl;
			cin >> option2b;
			if (option2b == 1)
			{
				cout << "You start wondering with your phone in the air waiting to find a singla to call someone." << endl;
				cout << "While wondering you were too fouced on your phone you didnt see someone follwoing you...." << endl;
				cout << "You stop because you have found a signal but before you can make a phone call." << endl;
				cout << "The man following you bashes your head with a blunt object.." << endl;
				cout << "You Lose! Try Again!" << endl;
			}
			else if (option2b == 2)
			{
				cout << "You decide to wait for someone to stop and help you." << endl;
				cout << "after waiting for what seems like hours, you see headlights." << endl;
				cout << "You jump of and run into the middle of the road but..." << endl;
				cout << "The car doesnt seem like its slowing down." << endl;
				cout << "While you stand their helplessly the car speeds up and runs you over. " << endl;
				cout << "You Lose! Try Again!" << endl;
			}
		}
		else if (option2 == 2)
		{
			int option2a;
			cout << "You open your tunk." << endl;
			cout << "You see Jumper Cables, A Spare Tire, and your Suit Case." << endl;
			cout << "1: Grab Jumper Cables." << endl;
			cout << "2: Grab Spare Tire." << endl;
			cout << "3: Grab Suit Case." << endl;
			cout << "4: Close Trunk." << endl;
			cin >> option2a;
			if (option2a == 1)
			{
				int option2a1;
				cout << "You grab the jumper cables but then you hear something behind you...." << endl;
				cout << "1: Do you turn around." << endl;
				cout << "2: Do you ignore the noise." << endl;
				cin >> option2a1;
				if (option2a1 == 1)
				{
					cout << "You turn around and see a figure with a mask." << endl;
					cout << "Before you can react the figure hits you across your head and you blackout." << endl;
					cout << "You Lose! Try Again!";
				}
				else if (option2a1 == 2)
				{
					cout << "You ignore the sound." << endl;
					cout << "Seconds later you feel an object smash into your head and you blackout." << endl;
					cout << "You Lose! Try Again!";
				}
			} 
			else if (option2a == 2)
			{
				int option2a1;
				cout << "You grab the spare tire but then you hear something behind you...." << endl;
				cout << "1: Do you turn around." << endl;
				cout << "2: Do you ignore the noise." << endl;
				cin >> option2a1;
				if (option2a1 == 1)
				{
					cout << "You turn around and see a figure with a mask." << endl;
					cout << "Before you can react the figure hits you across your head and you blackout." << endl;
					cout << "You Lose! Try Again!";
				}
				else if (option2a1 == 2)
				{
					cout << "You ignore the sound." << endl;
					cout << "Seconds later you feel an object smash into your head and you blackout." << endl;
					cout << "You Lose! Try Again!";
				}
			}
			else if (option2a == 3)
			{
				int option2a1;
				cout << "You grab the suit case but then you hear something behind you...." << endl;
				cout << "1: Do you turn around." << endl;
				cout << "2: Do you ignore the noise." << endl;
				cin >> option2a1;
				if (option2a1 == 1)
				{
					cout << "You turn around and see a figure with a mask." << endl;
					cout << "Before you can react the figure hits you across your head and you blackout." << endl;
					cout << "You Lose! Try Again!";
				}
				else if (option2a1 == 2)
				{
					cout << "You ignore the sound." << endl;
					cout << "Seconds later you feel an object smash into your head and you blackout." << endl;
					cout << "You Lose! Try Again!";
				}
			}
			else if (option2 == 4)
			{
				int option2a1;
				cout << "You close your trunk." << endl;
				cout << "1: You can start walking hoping to find someone." << endl;
				cout << "2: You can stay and wait by your car." << endl;
				cin >> option2a1;
				if (option2a1 == 1)
				{
					cout << "You start walking hoping to run into another person." << endl;
					cout << "While walking you find a strange man on the side of the road." << endl;
					cout << "You walk up to him and ask for his help." << endl;
					cout << "He looks at you for a second and before he even says anything.." << endl;
					cout << "He grabs a blunt object and hits your head and you blackout." << endl;
					cout << "You Lose! Try Again!" << endl;
				}
				else if (option2a1 == 2)
				{
					cout << "As you sit and wait for someone to drive by, it fall asleep..." << endl;
					cout << "Next thing you remeber is waking up in the hospital." << endl;
					cout << "Congrats you survived, barely though.. he was close..." << endl;
					return 0;
				}
			}
			else
			{
				return 0;
			}

		}
		else
		{
			return 0;
		}



	}
	else if (option1 == 2)
	{
		int option4;
	    cout << "You check your phone and see that your reception is gone." << endl;
		cout << "You remember that you need reception to use your map" << endl;
		cout << "1: You can wonder around to try and find a signal to make a phone call" << endl;
		cout << "2: You can sit by your car and wait for someone to drive by" << endl;
		cin >> option4;
		if (option4 == 1)
		{
			cout << "You start wondering with your phone in the air waiting to find a singla to call someone." << endl;
			cout << "While wondering you were too fouced on your phone you didnt see someone follwoing you...." << endl;
			cout << "You stop because you have found a signal but before you can make a phone call." << endl;
			cout << "The man following you bashes your head with a blunt object.." << endl;
			cout << "You Lose! Try Again!" << endl;
		}
		else if (option4 == 2)
		{
			cout << "While you sit on your car and wait you start falling asleep." << endl;
			cout << "To stay awake, you get up and walk around." << endl;
			cout << "After what feels like hours of waiting, you look at your phone again." << endl;
			cout << "You see you finally have reception, you quickly call the police." << endl;
			cout << "To your surprise they pick-up and after a short call they say that they are on their way." << endl;
			cout << "After another hour of waiting you police light heading up the mountain." << endl;
			cout << "Congrats you have survived the scary night!" << endl;
		}
		else
		{
			return 0;
		}
		
		
	}
	else
	{
		return 0;
	}
}
