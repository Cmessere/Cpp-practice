#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

constexpr auto EASY_MAX = 10;
constexpr auto MEDIUM_MAX = 100;
constexpr auto HARD_MAX = 1000;

using namespace std;

void startGame();
void askForAnotherGame();
void guessingGame(const int& difficulty);
void getMaxPossibleNumber(const int difficulty, int& maxNumber);
void getDifficulty(int& difficulty);
void getRandomTarget(const int& maxNumber, int& target);

int main()
{
    startGame();
}

void startGame()
{
    int difficulty, maxNumber;

    getDifficulty(difficulty);
    getMaxPossibleNumber(difficulty, maxNumber);
    guessingGame(maxNumber);
}

void getDifficulty(int& difficulty)
{
    cout << "Let's play Guess the Number." << endl;
    cout << "Pick a difficulty level(1, 2, or 3) : ";
    cin >> difficulty;

    while (cin.fail() && difficulty != 1 && difficulty != 2 && difficulty != 3) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Only numbers allowed. Please try again" << endl;
        cin >> difficulty;
    }
}

void getMaxPossibleNumber(int difficulty, int& maxNumber)
{
    switch (difficulty) {
    case 1:
        maxNumber = EASY_MAX;
        break;
    case 2:
        maxNumber = MEDIUM_MAX;
        break;
    case 3:
        maxNumber = HARD_MAX;
        break;
    }
}

void getRandomTarget(const int& maxNumber, int& target) {
    srand(time(NULL));

    target = rand() % maxNumber + 1;
}

void guessingGame(const int& maxNumber) {

    int tries = 0, target, currentInput;
    bool found = false;

    getRandomTarget(maxNumber, target);
    cout << "I have my number.What's your guess? ";

    while (!found) {
        cin >> currentInput;

        tries++;
        while (cin.fail() ) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Only numbers allowed. Please try again" << endl;
            tries++;
        }

        if (currentInput == target) {
            cout << "You got it in " << tries << " guesses!" << endl;
            found = true;
            askForAnotherGame();
            break;
        }

        if (currentInput < target && currentInput != 0) {
            cout << "Too low. Guess again: ";
        }
        else if(currentInput > target && currentInput != 0){
            cout << "Too high. Guess again: ";
        }
    }
}

void askForAnotherGame() {
    string choice;
    
    cout << "Do you want to play again? ";
    cin >> choice;

    std::for_each(choice.begin(), choice.end(), [](char& c) {c = ::toupper(c); });

    while (choice != "N" && choice != "Y")
    {
        cout << "Not a valid choice, please try again ('N' / 'Y')" << endl;
        cin >> choice;
    }

    if (choice == "Y")
        startGame();
    else
        cout << "Goodbye then!" << endl;
}

