/*
	KeywordsII
	10 hidden words picks 3 words out of 10 every simulation
	You need to guess the word
	you cant see the word and dont get hints
	keeps track of user guesses and incorrect guesses
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <ctime>

using namespace std;

void guessFunc()
{
	// Create a collection of 10 words you had written down manually
	vector<string> words;
	words.push_back("BRAVO");
	words.push_back("INDICA");
	words.push_back("ROMIO");
	words.push_back("JONNY");
	words.push_back("BEAR");
	words.push_back("GLASS");
	words.push_back("BRILLIANT");
	words.push_back("ANCHOR");
	words.push_back("COFFEE");
	words.push_back("BILLBOARD");

	// Create an int var to count the number of simulations being run starting at 1
	int simulation = 1;

	// Display the simulation # is starting to the recruit. 
beginning:
	cout << "This is simulation number " << simulation << endl;

	// Pick new 3 random words from your collection as the secret code word the recruit has to guess. 
	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());

	const int MAX_WRONG = 0;
	int wrong = 10; //Number of wrong guesses
	string THE_WORD = words[0]; //Random word
	string soFAR(THE_WORD.size(), '-');
	string used = " ";

	// While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
	while ((wrong > MAX_WRONG) && (soFAR != THE_WORD))
	{
		//     Tell recruit how many incorrect guesses he or she has left
		cout << "You have " << wrong << " incorrect guesses left" << endl;
		//     Show recruit the letters he or she has guessed
		cout << "You have used the following letters: " << used << endl;
		//     Show player how much of the secret word he or she has guessed
		cout << soFAR << endl;


		//     Get recruit's next guess
		char guess;
		cout << "Please enter your guess: ";
		cin >> guess;
		guess = toupper(guess);

		//     While recruit has entered a letter that he or she has already guessed
		while (used.find(guess) != string::npos)
		{
			cout << "You have already guessed: " << guess << endl;
			cout << "Please enter a different letter: ";
			//          Get recruit ’s guess
			cin >> guess;
			guess = toupper(guess);
		}
		//     Add the new guess to the group of used letters
		used += guess;

		//     If the guess is in the secret word
		if (THE_WORD.find(guess) != string::npos)
		{
			//          Tell the recruit the guess is correct
			cout << guess << " is in the word" << endl;

			//          Update the word guessed so far with the new letter
			for (int i = 0; i < THE_WORD.length(); ++i)
			{
				if (THE_WORD[i] == guess)
				{
					soFAR[i] = guess;
				}
			}
		}
		else
		{
			//          Tell the recruit the guess is incorrect
			cout << guess << " is not in the word." << endl;
			//          Increment the number of incorrect guesses the recruit has made
			--wrong;
		}
	}


	// If the recruit has made too many incorrect guesses
	if (wrong == MAX_WRONG)
	{
		//     Tell the recruit that he or she has failed the Keywords II course.
		cout << "You failed!" << endl;
		cout << "The word was: " << THE_WORD << endl;
	}
	else
	{
		//     Congratulate the recruit on guessing the secret words
		cout << "Congrats you guessed it!" << endl;
		cout << "The word was: " << THE_WORD << endl;

	}
	// Ask the recruit if they would like to run the simulation again
	char yn;
	cout << "Would you like to try the simulation again? Y or N: ";
	cin >> yn;

	// If the recruit wants to run the simulation again
	if (yn == 'Y' || yn == 'y')
	{
		//     Increment the number of simulations ran counter
		++simulation;
		//     Move program execution back up to // Display the simulation # is starting to the recruit. 
		goto beginning;
	}
	else
	{
		//     Display End of Simulations to the recruit
		cout << "Number of Simulations played: " << simulation << endl;
	}
	//     Pause the Simulation with press any key to continue
	system("pause");
}

int main()
{
	// Display Title of the program to the user
	cout << "---------------------Welcome to KeywordsII---------------------" << endl;
	cout << "---------------------Can You Guess the Word---------------------" << endl;

	// Ask the recruit to log in using their name
	// Hold the recruit's name in a var, and address them by it throughout the simulation.
	cout << "Please Login with your name: " << endl;
	string name;
	cin >> name;
	cout << "Welcome to KeywordsII " << name << endl;

	// Display an overview of what Keywords II is to the recruit
	// Display directions to the recruit on how to use Keywords
	cout << "Congrats on passing your first Keywords test, that was meant to be easy, can you break the new Keywrods?" << endl;
	cout << "1. You get 10 incorrect guesses" << endl;
	cout << "2. You dont get any hints" << endl;
	cout << "3. You dont see the scrambled word" << endl;
	cout << "However the program will keep track of which letters you have used" << endl;
	cout << "Each stimulation the program will pick 3 random words for you to de-scramble" << endl;
	cout << "Each letter guessed you will recive feedback" << endl;

	guessFunc();
}
