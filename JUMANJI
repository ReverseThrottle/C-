/*
Zachary Hopping
09/17/20
JUMANJI recreating Lost Fortune with a JUMANJI twist
*/

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	//creating variable for user to pick character  
	string avatar1 = "Dr.Smolder Bravestone";
	string avatar2 = "Franklin Finbar";
	string avatar3 = "Ruby Roundhouse";
	string avatar4 = "Professor Shelly Oberon";
	char option;

	cout << "Welcome to the jungle!" << endl;
	cout << "Please Select your Avatar: " << endl;

	//Display user options user must select 1-4 otherwise with throw an error
	cout << "\n1. Dr. Smolder Bravestone" << endl;
	cout << "2. Franklin Finbar" << endl;
	cout << "3. Ruby Roundhouse" << endl;
	cout << "4. Professor Shelly Oberon" << endl;

	cout << "\nSelect Avatar 1-4: ";
	//Taking user input
	cin >> option;

	//switch statement which checks what user inputs
	//Will display a welcoming screen depending on user selection
	switch (option)
	{
		case '1':
			cout << "\nWelcome " << endl;
			cout << "\nStrengths: \nFearless\nClimbing\nSpeed\nBoomerand\n\nWeakness:\nNone\n";
			break;
		case '2':
			cout << "\nWelcome Franklin Finbar" << endl;
			cout << "\nStrengths:\nZoology\nWeapons Valet\n\nWeakness:\nCake\nSpeed\nStrength\n";
			break;
		case '3':
			cout << "\nWelcome Ruby Roundhouse" << endl;
			cout << "\nStrengths:\nKarate\nT'ai Chi\nAikido\nDance Fighting\n\nWeakness:\nVenom\n";
			break;
		case '4':
			cout << "\nWelcome Professor Shelly Oberon" << endl;
			cout << "\nStrengths:\nCartography\nArchaeology\nPaleontology\n\nWeakness:\nEndurance\n";
			break;

		default: cout << "Invalid Option" << endl;

	}
	
	//Tell Story
	cout << "\nYour goal is to complete levels gain XP and level up your powers to beat the final level" << endl;
	cout << "Your first goal is to discover where you are at and to find the missing peice of the map" << endl;
	cout << "After wondering awhile you come across a twon" << endl;
	cout << "You can either enter or keep traveleing?" << endl;
	
	//User input decide the fate of the game
	char town;
	cout << "\n1. Enter Town" << endl;
	cout << "\n2. Keep Traveling" << endl;
	cin >> town;

	switch (town)
	{
	case '1':
		cout << "You enter the town and ask the locals questions during this time " << avatar2 << " has disapeared!" << endl;
		cout << "You see " << avatar2 << " in the town market and see him buying a cake he eats it and dies" << endl;
		break;
	case '2':
		cout << "You decide to keep traveling and follow the map" << endl;
		break;
	}

	cout << "You have been following the map for sometime and you reach a canyon" << endl; 
	cout << "You can either enter through the canyon or go around" << endl;
	cout << "Entering through the canyon will save much time but is more dangerous" << endl;

	//Another user input where they decide the fate of the game
	char canyon;
	cout << "\n1. Enter Canyon" << endl;
	cout << "\n2. Go around" << endl;
	cin >> canyon;

	switch (canyon)
	{
	case '1':
		cout << "Night fall is upon you as you enter the canyon the only light is from " << avatar1 << ". " << endl;
		cout << avatar4 << " stops becasue he was tired" << endl;
		cout << "While he was stopped he looked behind him and saw a creature coming towards him it was too dark to see what it was" << endl;
		cout << "He could only see his yellow eyes" << endl;
		cout << avatar4 << " let out a lowd scream" << endl;
		cout << "RUNNNNNNNNNNNNN!" << endl;
		cout << avatar1 << " yells throw me my weapon! " << avatar2 << " reaches in his backpack for his weapon and throws it to " << avatar1 << endl;
		cout << avatar1 << " Throws it at the creature hitting its head the creature came falling to the ground with a loud bang as the rest continued to run away" << endl;
		cout << "They had finally reached it to the final level!" << endl;
		break;
	case '2':
		cout << "While walking around the canyon it was dark and hard to see." << endl;
		cout << avatar4 << " need to rest becasue he was tired. When " << avatar4 << " turned around he saw a creature flying towards him" << endl;
		cout << "Before the others knew it " << avatar4 << " was falling down into the canyon" << endl;
		cout << "The only thing they heard was him screaming!" << endl;
		break;
	

	}
}
