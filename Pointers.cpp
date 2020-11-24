/*
	Zachary Hopping
	11-24-20
	Pointers only reqs is to create 2 pointers that have different data types 
	& have 2 or more functions, pass a pointer into the function
*/

//preprocessor
#include<iostream>
#include<string>
#include<sstream>

using namespace std;
//function prototype
void nameSwap(string* const pX, string* const pY);
void scoreSwap(int* const pX, int* const pY);

int main()
{
	//variables
	int Player1;
	int Player2;
	string playerName1;
	string playerName2;
	//takes users names
	cout << "Please enter player 1's name: ";
	cin >> playerName1;
	cout << "Please enter player 2's name: ";
	cin >> playerName2;
	//greets players and explains the game
	cout << "Welcome " << playerName1 << " and " << playerName2 << endl;
	cout << "Enter 2 different scores for player1 & player2" << endl;
	cout << "Who wants the higher score??" << endl;
	//asks user to enter score for each player
	cout << "Please enter a number for player1: ";
	cin >> Player1;
	cout << "Please enter another number for player2: ";
	cin >> Player2;
	//checks to make sure the number is not the same
	if (Player2 == Player1)
	{
		cout << "Please enter a different number: ";
		cin >> Player2;
		cout << endl;
	}
	//prints out the users name and score
	else
	{
		cout << playerName1 << " Score: " << Player1 << endl;
		cout << playerName2 << " Score: " << Player2 << endl;

	}
	//asks user if they are happy with the score they got
	char option;
	cout << "Are you happy with that score [Y]es/[N]o? ";
	cin >> option;
	//checks what the suer said in this case it deosnt matter the outcome is the same
	if (option == 'Y' || option == 'y')
	{
		//Flips score for player 1 and player2
		cout << "Haha you are playing with a cheater look at the score now!" << endl;
		scoreSwap(&Player1, &Player2);
		cout << playerName1 << " Score: " << Player1 << endl;
		cout << playerName2 << " Score: " << Player2 << endl;
		system("pause");
		//flips players name instead of score back to the original scores
		cout << "Oh wait the cheater has been bamboozled, look at the score!" << endl;
		nameSwap(&playerName1, &playerName2);
		cout << playerName1 << " Score: " << Player1 << endl;
		cout << playerName2 << " Score: " << Player2 << endl;

	}
	else
	{
		//Flips score for player 1 and player2
		cout << "Haha you are playing with a cheater look at the score now!" << endl;
		scoreSwap(&Player1, &Player2);
		cout << playerName1 << " Score: " << Player1 << endl;
		cout << playerName2 << " Score: " << Player2 << endl;
		system("pause");
		//flips players name instead of score back to the original scores
		cout << "Oh wait the cheater has been bamboozled, look at the score!" << endl;
		nameSwap(&playerName1, &playerName2);
		cout << playerName1 << " Score: " << Player1 << endl;
		cout << playerName2 << " Score: " << Player2 << endl;

	}

}

//both functions one flips players score 
void scoreSwap(int* const pX, int* const pY)
{
	int temp = *pX;
	*pX = *pY;
	*pY = temp;
}
//this one flips players name 
void nameSwap(string* const pX, string* const pY)
{
	string temp = *pX;
	*pX = *pY;
	*pY = temp;
}
