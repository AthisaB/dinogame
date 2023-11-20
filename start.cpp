#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum Choice { ROCK, PAPER, SCISSORS };
enum Result { WIN, LOSE, DRAW };

Choice getComputerChoice() {
    return static_cast<Choice>(rand() % 3);
}

Choice getUserChoice() {
    int choice;
    cout << "Rock (0), Paper (1), Scissors (2): ";
    cin >> choice;
    return static_cast<Choice>(choice);
}

Result determineWinner(Choice user, Choice computer) {
    if (user == computer) {
        return DRAW;
    } else if ((user == ROCK && computer == SCISSORS) ||
               (user == PAPER && computer == ROCK) ||
               (user == SCISSORS && computer == PAPER)) {
        return WIN;
    } else {
        return LOSE;
    }
}

void displayChoice(Choice choice) {
    switch (choice) {
        case ROCK: cout << "Rock"; break;
        case PAPER: cout << "Paper"; break;
        case SCISSORS: cout << "Scissors"; break;
    }
}

void displayResult(Result result) {
    switch (result) {
        case WIN: cout << "You win!\n"; break;
        case LOSE: cout << "You lose.\n"; break;
        case DRAW: cout << "It's a draw.\n"; break;
    }
}

int main() {
    srand(time(0)); // Seed for random number generation

    // Clear the screen
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif

    char playAgain = 'y';
    while (playAgain == 'y') {
        Choice userChoice = getUserChoice();
        Choice computerChoice = getComputerChoice();

        displayChoice(userChoice);
        cout << " vs ";
        displayChoice(computerChoice);
        cout << endl;

        Result gameResult = determineWinner(userChoice, computerChoice);
        displayResult(gameResult);

        cout << "Play again? (y/n): ";
        cin >> playAgain;
    }

    return 0;
}
