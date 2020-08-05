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

int main()
{
	int people, pizzas, pieces = 0;

    people = getInput("people");
    pizzas = getInput("pizzas");
	
	pieces = pizzas * SLICES;

	cout << "Each person gets " << pieces / people << " pieces of pizzas." << endl;
	cout << "There are " << pieces % people << " leftover pieces." << endl;
}