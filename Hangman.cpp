/*
	Zachary Hopping
	10-27-2020
	Interactive Fiction
	Create an interactive fiction game/story using more than one function our code must do something and be interactive
	ADD COMMENTS AND ADD A FUNCTIONALITY WHERE IT KEEP TRACKS OF USER GUESSES
*/

#include <iostream>
#include <string>
#include <algorithm>


using namespace std;


void playerFunc(string player1, string player2);
int numGuessGame(string player1, string player2);
string gameFunc(string player1, string player2);


int main()
{
	string PLAYER1, PLAYER2, word;
	int guessWord = 1;
	cout << "Welcome to Hangman" << endl;
	cout << "Can you guess the word before you die?" << endl;
	cout << "Enter PLAYER1 name" << endl;
	cin >> PLAYER1;
	cout << "Enter PLAYER2 name" << endl;
	cin >> PLAYER2;
	playerFunc(PLAYER1, PLAYER2);
	guessWord = numGuessGame(PLAYER1, PLAYER2);
	cout << guessWord;
	word = gameFunc(PLAYER1, PLAYER2);
	cout << word;


}

void playerFunc(string player1, string player2)
{
	string result;
	result = player1 + player2;
	cout << "Welcome " << player1 << " & " << player2 << endl;
}

int numGuessGame(string player1, string player2)
{
	int numGuess = 1;
	cout << player2 << " how many guesses do you need?" << endl;
	cin >> numGuess;
	if (numGuess == 12)
	{
		cout << "Number of Guesses: ";
	}
	else
	{
		cout << "Number of Guesses: ";
	}
	return numGuess;
}

string gameFunc(string player1, string player2)
{
	
	string word, guess;
	int wrong = 12;
	int numGuesses = 0;
	cout << endl << player1 << " please enter a word for " << player2 << " to guess" << endl;
	cin >> word;
	string censoredWord;

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
		cout << "You have " << wrong << " incorrect guesses" << endl;
		cout << "Guess: ";
		cin >> guess;

		// Determines if the guess is more than one character.
		if (guess.length() > 1) 
		{
			cout << "That is more than one character.";
		}

		// Determines if the guess is a lowercase letter.
		else if (guess[0] > 'z' || guess[0] < 'a') 
		{
			cout << "Your guess must be a lowercase letter. ";
		}

		// First, the program finds the guess in the word. If it is found, the
		// dashes at which their guess occurs will be replaced with the user's
		// guess. Otherwise, the number of guesses will be decremented by 1.
		else 
		{
			size_t index_found = word.find(guess);
			if (index_found != string::npos) {
				for (int i = 0; i < word.length(); i++) 
				{
					if (word[i] == guess[0]) 
					{
						censored[i] = guess[0];
					}
				}
				cout << "Correct!" << endl;
				numGuesses++;
			}
			else 
			{
				cout << "Wrong!" << endl;
				wrong = wrong - 1;
				numGuesses++;
			}
		}
		if (wrong == 11)
		{
			for (int x = 0; x < 30; x++)
			{
				cout << endl;
			}
			cout << "I" << endl;
		}
		else if (wrong == 10)
		{
			for (int x = 0; x < 30; x++)
			{
				cout << endl;
			}
			cout << "I" << endl;
			cout << "I" << endl;
		}
		else if (wrong == 9)
		{
			for (int x = 0; x < 30; x++)
			{
				cout << endl;
			}
			cout << "I" << endl;
			cout << "I" << endl;
			cout << "I" << endl;
		}
		else if (wrong == 8)
		{
			for (int x = 0; x < 30; x++)
			{
				cout << endl;
			}
			cout << "I" << endl;
			cout << "I" << endl;
			cout << "I" << endl;
			cout << "I" << endl;
		}
		else if (wrong == 7)
		{
			for (int x = 0; x < 30; x++)
			{
				cout << endl;
			}
			cout << "I" << endl;
			cout << "I" << endl;
			cout << "I" << endl;
			cout << "I" << endl;
			cout << "I" << endl;
		}
		else if (wrong == 6)
		{
			for (int x = 0; x < 30; x++)
			{
				cout << endl;
			}
			cout << "I===" << endl;
			cout << "I" << endl;
			cout << "I" << endl;
			cout << "I" << endl;
			cout << "I" << endl;
		}
		else if (wrong == 5)
		{
			for (int x = 0; x < 30; x++)
			{
				cout << endl;
			}
			cout << "I===" << endl;
			cout << "I  O" << endl;
			cout << "I" << endl;
			cout << "I" << endl;
			cout << "I" << endl;
		}
		else if (wrong == 4)
		{
			for (int x = 0; x < 30; x++)
			{
				cout << endl;
			}
			cout << "I===" << endl;
			cout << "I  O" << endl;
			cout << "I  |" << endl;
			cout << "I" << endl;
			cout << "I" << endl;
		}
		else if (wrong == 3)
		{
			for (int x = 0; x < 30; x++)
			{
				cout << endl;
			}
			cout << "I===" << endl;
			cout << "I  O" << endl;
			cout << "I -|" << endl;
			cout << "I" << endl;
			cout << "I" << endl;
		}
		else if (wrong == 2)
		{
			for (int x = 0; x < 30; x++)
			{
			cout << endl;
			}
			cout << "I===" << endl;
			cout << "I  O" << endl;
			cout << "I -|-" << endl;
			cout << "I" << endl;
			cout << "I" << endl;
		}
		else if (wrong == 1)
		{
			for (int x = 0; x < 30; x++)
			{
			cout << endl;
			}
			cout << "I===" << endl;
			cout << "I  O" << endl;
			cout << "I -|-" << endl;
			cout << "I /" << endl;
			cout << "I" << endl;
		}
		else if (wrong == 0)
		{
			for (int x = 0; x < 30; x++)
			{
			cout << endl;
			}
			cout << "I===" << endl;
			cout << "I  O" << endl;
			cout << "I -|-" << endl;
			cout << "I / /" << endl;
			cout << "I YOU ARE DEAD" << endl;
		}
	}

	

	// Determines whether the player lost or won. Either way, the word will
	// still be printed so they know what the word was.
	if (censored == word) {
		cout << "You win!" << endl;
		cout << "It took you " << numGuesses << " tries to guess the word" << endl;
		cout << "The word was: ";
		
	}
	else {
		cout << "You lose." << endl;
		cout << "The word was: ";
	}
	return word;
}

