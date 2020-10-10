/*
	Zachary Hopping
	09-29-2020
    Skynet-HK

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
	int binCounter = 1;
	bool Testbegin = false;

	do
	{
		do
		{
			Testbegin = false;

			cout << "Skynet-HK Binary guess scan number " << binCounter << endl;
			cout << "The target is located at " << target << endl;
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

}
