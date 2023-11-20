#include <iostream>
#include <cstdlib>
#include <ctime>
#include "dinosaur.h"
#include <limits>

using namespace std;

enum Choice
{
    ROCK,
    PAPER,
    SCISSORS
};
enum Result
{
    WIN,
    LOSE,
    DRAW
};

Choice getComputerChoice()
{
    return static_cast<Choice>(rand() % 3);
}

Choice getUserChoice()
{
    int choice;
    cout << "Rock (0), Paper (1), Scissors (2): ";
    cin >> choice;
    return static_cast<Choice>(choice);
}

Result determineWinner(Choice user, Choice computer)
{
    if (user == computer)
    {
        return DRAW;
    }
    else if ((user == ROCK && computer == SCISSORS) ||
             (user == PAPER && computer == ROCK) ||
             (user == SCISSORS && computer == PAPER))
    {
        return WIN;
    }
    else
    {
        return LOSE;
    }
}

void displayChoice(Choice choice)
{
    switch (choice)
    {
    case ROCK:
        cout << "Rock";
        break;
    case PAPER:
        cout << "Paper";
        break;
    case SCISSORS:
        cout << "Scissors";
        break;
    }
}

void displayResult(Result result)
{
    switch (result)
    {
    case WIN:
        cout << "You win!\n";
        break;
    case LOSE:
        cout << "You lose.\n";
        break;
    case DRAW:
        cout << "It's a draw.\n";
        break;
    }
}

int main()
{
    srand(time(0)); // Seed for random number generation

// Clear the screen
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    char playAgain = 'y';
    while (playAgain == 'y')
    {
        Dinosaur a = Dinosaur("Tyrannosaurus Rex", 200, 150);
        Dinosaur b = Dinosaur("Stegosaurus", 150, 100);

        while (a.getHealth() > 0 || b.getHealth() > 0)
        {
            cout << a.getName() << " vs " << b.getName() << "!" << endl;

            Choice userChoice = getUserChoice();
            Choice computerChoice = getComputerChoice();

            displayChoice(userChoice);
            cout << " vs ";
            displayChoice(computerChoice);
            cout << endl;

            Result gameResult = determineWinner(userChoice, computerChoice);
            switch (gameResult)
            {
            case WIN:
                b.takeDamage(a.getAttack() / 5);
                cout << "You won the duel!" << endl;
                break;
            case LOSE:
                a.takeDamage(b.getAttack() / 5);
                cout << "You lost the duel!" << endl;
                break;
            case DRAW:
                a.takeDamage(b.getAttack() / 8);
                b.takeDamage(a.getAttack() / 8);
                cout << "It's a draw!" << endl;
                break;
            }

            cout << a.getHealth() << " " << b.getHealth() << endl;
            cout << "Press Enter to Continue" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
#ifdef _WIN32
            system("cls");
#else
            system("clear");
#endif
        }

        cout << "Play again? (y/n): ";
        cin >> playAgain;
    }

    return 0;
}
