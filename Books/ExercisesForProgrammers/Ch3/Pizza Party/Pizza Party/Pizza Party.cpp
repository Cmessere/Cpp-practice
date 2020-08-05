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


int main()
{
	int people, pizzas, pieces = 0;

    people = getInput("people");
    pizzas = getInput("pizzas");
	
	pieces = pizzas * SLICES;

    printSlicesPerPerson(pieces / people);
    printSlicesRemaining(pieces % people);
}