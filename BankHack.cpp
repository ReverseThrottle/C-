/*
	Zachary Hopping
	11-17-2020
	Hacking the bank 
	Taking the money from one account and maving it into a different account using functions and references
*/

#include<iostream>
#include<string>

using namespace std;

void checkBalFunc(int terroristAcc, int coffeeAcc); //balance check for both accounts
void hackedBalFunc(int&terroristAcc, int&coffeeAcc); //hacked balance check which switch values
void displayBalFunc(int terroristAcc, int coffeeAcc); //displays both account balances 


int main()
{
	//Account Balances
	int terroristAcc = 1500000;
	int coffeeAcc = 150;

	//Displays accounts original balances
	cout << "Original Balance: " << endl;
	displayBalFunc(terroristAcc, coffeeAcc);
	
	//Does a balance check of both accounts nothing should from original balances
	cout << "\n\nBalance Check....." << endl;
	checkBalFunc(terroristAcc, coffeeAcc);
	displayBalFunc(terroristAcc, coffeeAcc);

	//Does a hacked balance check of both accounts and should flip balances so coffee shop is now RICH!
	cout << "\n\nHacked Balance Check....." << endl;
	hackedBalFunc(terroristAcc, coffeeAcc);
	displayBalFunc(terroristAcc, coffeeAcc);

	return 0;

}

void checkBalFunc(int terroristAcc, int coffeeAcc)
{
	//checks balance of both accounts 
	int check = terroristAcc;
	terroristAcc = coffeeAcc;
	coffeeAcc = check;
}

void hackedBalFunc(int& terroristAcc, int& coffeeAcc)
{
	//using references to flip account values
	int check = terroristAcc;
	terroristAcc = coffeeAcc;
	coffeeAcc = check;
}

void displayBalFunc(int terroristAcc, int coffeeAcc)
{
	//just displays balance of both accounts
	cout << "Joe's Coffee Shop Account Balance: " << coffeeAcc << endl;
	cout << "Terrorists Account Balance: " << terroristAcc << endl;
}
