/*
	Zachary Hopping
	09-29-2020
	Ai into Skynet HK-Aerial

	Goal is to create 4 players to guess the targets location and keep track of many guesses it took each player 
	human
	ai guess
	linear guess
	binary guess

*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(time(NULL)); // creates random number

	//Initialization of variables
	int searchGridHighNum = 64;
	int searchGridLowNum = 1;
	int target = rand() % 64 + 1;
	int guess = rand() % 64 + 1;
	int randGuess;
	int humanGuess;
	int linGuess = 1;
	int humanCounter = 1;
	int randCounter = 1;
	int linCounter = 1;
	int binCounter = 1;
	
	bool testBegin = false;
	bool TestBegin = false;
	bool testbegin = false;
	bool Testbegin = false;
	

	cout << "Skynet-HK searching for enemy on 8x8 grid..." << endl;
	cout << "The target is located at " << target << endl;
	cout << "Skynet-HK Initializing..." << endl;
	cout << "------------------------------------------------------------------------------" << endl;

	//Human Guess thats uses a do while loop 
	
	do
	{
		do
		{
			cout << "Skynet-HK Human scan number " << humanCounter << endl;
			cout << "Please guess targets location" << endl;
			cin >> humanGuess;

			//test guess with target 
			if (humanGuess < target)
			{
				cout << "Try again" << endl;
				++humanCounter;

			}
			else if (humanGuess > target)
			{
				cout << "Try again" << endl;
				++humanCounter;
			}
			else
			{
				break;
			}

		} while ((humanGuess != target)); //while guess does not = target

		//if guess does = target then
		if (humanGuess == target)
		{
			cout << "Human found target at location " << target << endl;
			cout << "Human took " << humanCounter << " predicitons to find the enemy." << endl;
			cout << "------------------------------------------------------------------------------" << endl;
		}

	} while (testBegin);
	

	//Random AI Guess thats uses a do while loop 

	do
	{
		do
		{
			cout << "Skynet-HK AI-guess scan number " << randCounter << endl;
			cout << "Please guess targets location" << endl;
			randGuess = rand() % 64 + 1;
			cout << randGuess << endl;
			
			//test guess with target 
			if (randGuess < target)
			{
				cout << "Try again" << endl;
				++randCounter;
			}
			else if (randGuess > target)
			{
				cout << "Try again" << endl;
				++randCounter;
			}
			else
			{
				break;
			}

		} while ((randGuess != target)); //while guess does not = target

		//if guess does = target then
		if (randGuess == target)
		{
			cout << "AI guess found target at location " << target << endl;
			cout << "AI guess took " << randCounter << " predicitons to find the enemy." << endl;
			cout << "------------------------------------------------------------------------------" << endl;
		}

	} while(TestBegin);
	 
	// Linear AI Guess thats uses a do while loop 

	do
	{
		do
		{
			cout << "Skynet-HK Linear guess scan number " << linCounter << endl;
			cout << "Please guess targets location" << endl;
			cout << linGuess << endl;

			//test guess with target 
			if (linGuess < target)
			{
				++linGuess;
				++linCounter;
				cout << "Try again" << endl;
			}
			else if (linGuess > target)
			{
				++linGuess;
				++linCounter;
				cout << "Try again" << endl;
			}
			else
			{
				break;
			}
		} while ((linGuess != target)); //while guess does not = target

		//if guess does = target then
		if (linGuess == target) 
		{
			cout << "Linear guess found target at location " << target << endl;
			cout << "Linear guess took " << linCounter << " predicitons to find the enemy." << endl;
			cout << "------------------------------------------------------------------------------" << endl;
		}

	} while (testbegin);

	//Binary Guess thats uses a do while loop 

	do
	{
		do
		{
			Testbegin = false;

			cout << "Skynet-HK Binary guess scan number " << binCounter << endl;
			cout << "Please guess targets location" << endl;

			//test guess with target 
			if (guess < target)
			{
				cout << "The location prediction of " << guess << " was lower than the target" << endl;
				searchGridLowNum = guess + 1;
				cout << "The new searchGridLowNumber = " << searchGridLowNum << endl;
				cout << "------------------------------------------------------------------------------" << endl;
			}
			else if (guess > target)
			{
				cout << "The location prediction of " << guess << " was higher than the target" << endl;
				searchGridHighNum = guess;
				cout << "The new searchGridLowNumber = " << searchGridHighNum << endl;
				cout << "------------------------------------------------------------------------------" << endl;
			}
			else
			{
				break;
			}
			
			guess = ((searchGridHighNum - searchGridLowNum) / 2) + searchGridLowNum;

			++binCounter;

		} while ((guess != target)); //while guess does not = target

		//if guess does = target then
		if (guess == target)
		{
			cout << "Binary guess found target at location " << target << endl;
			cout << "Binary guess took " << binCounter << " predicitons to find the enemy." << endl;
			cout << "------------------------------------------------------------------------------\n\n\n" << endl;
		}

	} while (Testbegin);

	//Outputs findings of all four search methods and how many predictions it took

	cout << "All drones have found target" << endl;
	cout << "Target was located at " << target << endl;
	cout << "==============================================================================" << endl << endl;

	cout << "Human took " << humanCounter << " predicitons to find the enemy." << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "AI guess took " << randCounter << " predicitons to find the enemy." << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "Linear guess took " << linCounter << " predicitons to find the enemy." << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "Binary guess took " << binCounter << " predicitons to find the enemy." << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	
	
	return 0;
}
