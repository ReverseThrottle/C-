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

void wordFunc(string player1, string player2);


int main()
{
	string PLAYER1,PLAYER2;  
	cout << "Welcome to Hangman" << endl;
	cout << "Can you guess the word before you die?" << endl;
	cout << "Enter PLAYER1 name" << endl;
	cin >> PLAYER1;
	cout << "Enter PLAYER2 name" << endl;
	cin >> PLAYER2;
	wordFunc(PLAYER1, PLAYER2);
	

}

void wordFunc(string player1, string player2)
{
	string result, word, guess;
	int wrong = 12;
	result = player1 + player2;
	cout << "Welcome " << player1 << " & " << player2 << endl;
	cout << player1 << " please enter a word for " << player2 << " to guess" << endl;
	cin>> word;

	for (int x = 0; x < 30; x++)
	{
		cout << endl;
	}
	string input{ word };  //https://stackoverflow.com/questions/29085414/replacing-text-in-a-string-with-hyphens
	string censored{ input };
	replace_if(censored.begin(), censored.end(), ::isalpha, '-');

	while (wrong > 0 && censored != word)
	{
		cout << censored << endl;
		cout << "You have " << wrong << " guesses" << endl;

		cout << player2 << " please guess one letter" << endl;
		cin.ignore();
		getline(cin, guess);

		if (guess.length() > 1)
		{
			cout << "Please only enter one letter";
		}

		else 
		{
			size_t index_found = word.find(guess);
			if (index_found != string::npos) 
			{
				for (int i = 0; i < word.length(); i++) 
				{
					if (word[i] == guess[0]) 
					{
						censored[i] = guess[0];
					}
				}
				cout << "Correct!" << endl;
			}
			else 
			{
				cout << "Incorrect!" << endl;
				wrong = wrong - 1;
			}
		}
	}

	if (censored == word)
	{
		cout << "You won!" << endl;
		cout << "The word was: " << word << endl;
	}
	else
	{
		cout << "You lose!" << endl;
		cout << "The word was: " << word << endl;
	}
}
