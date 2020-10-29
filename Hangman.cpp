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

	while (wrong > 0 && censored != word) {
		cout << censored << endl;
		cout << "You have " << wrong << " guesses" << endl;
		cout << "Guess: ";
		getline(cin, guess);

		// Determines if the guess is more than one character.
		if (guess.length() > 1) {
			cout << "That is more than one character.";
		}

		// Determines if the guess is a lowercase letter.
		else if (guess[0] > 'z' || guess[0] < 'a') {
			cout << "Your guess must be a lowercase letter. ";
		}

		// First, the program finds the guess in the word. If it is found, the
		// dashes at which their guess occurs will be replaced with the user's
		// guess. Otherwise, the number of guesses will be decremented by 1.
		else {
			size_t index_found = word.find(guess);
			if (index_found != string::npos) {
				for (int i = 0; i < word.length(); i++) {
					if (word[i] == guess[0]) {
						censored[i] = guess[0];
					}
				}
				cout << "Keep going!" << endl;
			}
			else {
				cout << "Wrong!" << endl;
				wrong = wrong - 1;
			}
		}
	}

	// Determines whether the player lost or won. Either way, the word will
	// still be printed so they know what the word was.
	if (censored == word) {
		cout << "You win!" << endl;
		cout << "The word was: " << word << endl;
	}
	else {
		cout << "You lose." << endl;
		cout << "The word was: " << word << endl;
	}
}
