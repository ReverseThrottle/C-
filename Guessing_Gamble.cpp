#include <iostream>
#include <cstdlib>
#include <ctime>

/*
 * Guessing game goal is to guess number 0-100 you have 5 tries
 * you can place a bet before the round starts
 * you can keep playing until you have no money
 */

//TODO - Need to work on logic for guessing number!

int main() {

    int guess, secret;
    int inc_guess = 0;
    float money = 10000;
    float bet;
    srand (time(nullptr));
    secret = rand() %100 +1;

    std::cout<<"Welcome to the guessing game\n";
    std::cout<<"You currently hold: "<<money<<" dollars\n\n";

    std::cout<<"Directions:\n[1]The goal is to guess the secret number\n[2]You have a total of 5 guesses\n";
    std::cout<<"[3]Before you begin guessing you are asked to place a bet\n";



    do {
        std::cout<<"Place your bet: ";
        std::cin>>bet;
        if (bet <= 0){
            std::cout << "You cant place a bet for zero dollars\n";
        }
        else if (bet >= money){
            std::cout << "You dont have that much money, sorry\n";
        }
    }while(bet == 0 || bet >= money);
    std::cout << "You placed a bet for: " << bet << "\n";

    do {
        std::cout << "\nGuess the number between 0-100: ";
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
        else if (guess > 100)
        {
            std::cout << "Guess too high, please pick a lower number\n";
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
