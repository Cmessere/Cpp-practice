#include <iostream>
#define SLICES 8;

using namespace std;

int main()
{
	int people, pizzas, pieces = 0;

	cout << "How many people?" << endl;
	cin >> people;
	cout << "How many pizzas?" << endl;
	cin >> pizzas;
	
	pieces = pizzas * SLICES;

	cout << "Each person gets " << pieces / people << " pieces of pizzas." << endl;
	cout << "There are " << pieces % people << " leftover pieces." << endl;
}