#include <iostream>
#define SLICES 8;

using namespace std;

int getInput(const string& question) {
    int input;

    cout << "How many " << question << "?" << endl;
    cin >> input;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Only numbers allowed. Please try again" << endl;
        cin >> input;
    }
    return input;
}

void printSlicesPerPerson(const int &slices) {
    if (slices == 1) {
        cout << "Each person gets " << slices << " piece of pizza." << endl;
    }
    else {
        cout << "Each person gets " << slices << " pieces of pizza." << endl;
    }

}

void printSlicesRemaining(const int& slices) {
    if (slices == 1) {
        cout << "There is " << slices << " leftover piece." << endl;
    }
    else {
        cout << "There are " << slices << " leftover pieces." << endl;
    }
}

void dividingPizzas() {
    int people, pizzas, pieces = 0;

    people = getInput("people");
    pizzas = getInput("pizzas");

    pieces = pizzas * SLICES;

    printSlicesPerPerson(pieces / people);
    printSlicesRemaining(pieces % people);
}

void calculatePizzas() {
    int people, pieces, pizzasNeeded;

    people = getInput("people");
    pieces = getInput("pieces");
    pizzasNeeded = (pieces * people) / SLICES;

    if(pizzasNeeded == 1)
        cout << "You need at least " << pizzasNeeded << " pizza." << endl;
    else
        cout << "You need at least " << pizzasNeeded << " pizzas." << endl;
}

int main()
{
    string choice;
    
    cout << "Do you want to 'divide' pizza? or 'calculate' how many you need?" << endl;
    cin >> choice;

    while ((choice != "divide" && choice != "calculate"))
    {
        cout << "That is not a valid option. Please try again: ";
        cin >> choice;
    }

    if (choice == "divide"){
        cout << "Dividing pizzas..." << endl;
        dividingPizzas();
    }
    else {
        calculatePizzas();
    }
}