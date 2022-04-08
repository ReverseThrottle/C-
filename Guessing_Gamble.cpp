#include <iostream>
#include <stdlib.h>
#include <time.h>

/*
 * Guessing game goal is to guess number 0-100 you have 5 tries
 * you can place a bet before the round starts
 * you can keep playing until you have no money
 */


int main() {

    int guess, secret;
    int inc_guess = 0;
    float money = 10000;
    float bet;
    srand (time(NULL));
    secret = rand() %100 +1;

    std::cout<<"Welcome to the guessing game\n";
    std::cout<<"You currently hold: "<<money<<" dollars\n\n";

    std::cout<<"Directions:\n[1]The goal is to guess the secret number\n[2]You have a total of 5 guesses\n";
    std::cout<<"[3]Before you begin guessing you are asked to place a bet\n";

    std::cout<<"Place your bet: ";
    std::cin>>bet;
    if (bet > money)
    {
        std::cout<<"You dont have that much money, sorry\n";
        std::cout<<"Try placing another bet: ";
        std::cin>>bet;

    }
    else if (bet <= 0)
    {
        std::cout<<"You cant place a bet for zero dollars\n";
        std::cout<<"Try placing another bet: ";
        std::cin>>bet;
    }
    std::cout<<"You placed a bet for: "<<bet<<"\n";

    do {
        std::cout << "Guess the number between 0-100: ";
        std::cin >> guess;
        std::cout << "You guessed: " << guess << "\n";
        if (guess < secret)
        {
            std::cout << "Higher!\n";
            ++inc_guess;
        }
        else if (guess > secret)
        {
            std::cout << "Lower!\n";
            ++inc_guess;
        }
        else
        {
            std::cout << "You guessed the correct number: " << guess << "\n";
            ++inc_guess;
            std::cout << "It took you: " << inc_guess << " guesses\n";
        }

    } while (guess != secret && inc_guess < 5);

    std::cout<<"You have no more guesses :(\n";
    std::cout<<"The number you were looking for was: "<<secret<<"\n";

    if (guess == secret)
    {
        money += bet;
        std::cout<<"You now have: "<<money<< " dollars\n";
    }
    else
    {
        money -= bet;
        std::cout<<"You now have: "<<money<< " dollars\n";
    }

    system("pause");
    return 0;
}
