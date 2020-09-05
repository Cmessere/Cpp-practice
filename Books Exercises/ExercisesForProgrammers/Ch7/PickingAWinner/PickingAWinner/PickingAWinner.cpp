#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "PickingAWinner.h"

using namespace std;

void pickAWinner(std::vector<string>& list);

void askToDraftAnotherWinner(std::string& choice, vector<string>& list);

void announceWinner(int& winner, std::vector<std::string>& list);

void promptForContestants(std::string& contestant, std::vector<std::string>& list);

int main()
{
    vector<string> list;
    pickAWinner(list);
}

void pickAWinner(std::vector<std::string> &list)
{
    srand(time(NULL));
    int winner;
    string contestant ="dud", choice;

    promptForContestants(contestant, list);
    announceWinner(winner, list);
    askToDraftAnotherWinner(choice, list);
}

void askToDraftAnotherWinner(std::string& choice, std::vector<string>& list)
{
        cout << "Do you want to pick another winner? ('Y'/'N')";
        cin >> choice;

        while (choice != "Y" && choice != "N") {
            cout << "Sorry, not a valid option. Please try again: ";
            cin >> choice;
        }

        if (choice == "Y") {
            pickAWinner(list);
        }
}
    

void announceWinner(int& winner, std::vector<std::string>& list)
{
    if (list.size() > 0) {
        winner = rand() % list.size();
        cout << "The winner is " << list[winner] << endl;
        list.erase(list.begin() + winner);
    }
    else {
        cout << "There are no more contestants to draw!" << endl;
    }
}

void promptForContestants(std::string& contestant, std::vector<std::string>& list)
{
    cin.ignore(cin.rdbuf()->in_avail(), '\n');

    while (true) {
        cout << "Enter a name: ";
        getline(cin, contestant);

        if (contestant.empty()) {
            break;
        }
        list.push_back(contestant);
    }
}
