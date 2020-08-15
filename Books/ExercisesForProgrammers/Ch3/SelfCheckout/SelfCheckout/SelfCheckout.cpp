#include <iostream>

using namespace std;

struct  PRODUCT {
	unsigned short quantity;
	double price;
};

int main()
{
	PRODUCT first, second, third;
	double subtotal = 0, tax = 0;

	cout << "Enter the price for item 1: " << endl;
	cin >> first.price;
	cout << "Enter the quantity for item 1: " << endl;
	cin >> first.quantity;

	cout << "Enter the price for item 2: " << endl;
	cin >> second.price;
	cout << "Enter the quantity for item 2: " << endl;
	cin >> second.quantity;

	cout << "Enter the price for item 3: " << endl;
	cin >> third.price;
	cout << "Enter the quantity for item 3: " << endl;
	cin >> third.quantity;

	subtotal = first.price * first.quantity + second.price * second.quantity + third.price * third.quantity;
	tax = subtotal * 5.5 / 100;

	cout << "Subtotal: $" << subtotal << endl;
	cout << "Tax: $" << tax << endl;
	cout << "Total: $" << tax + subtotal << endl;

}