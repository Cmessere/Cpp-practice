#include <iostream>

using namespace std;

struct  PRODUCT {
	unsigned short quantity;
	double price;
};

double getInput(const string& value, const unsigned short &number) {
	double size;

	cout << "Enter the " << value << " for item " << number << ": " << endl;
	cin >> size;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Only numbers allowed. Please try again" << endl;
		cin >> size;
	}
	return size;
}

int main()
{
	PRODUCT first, second, third;
	double subtotal = 0, tax = 0;

	first.price = getInput("price", 1);
	first.quantity = getInput("quantity", 1);

	second.price = getInput("price", 2);
	second.quantity = getInput("quantity", 2);

	third.price = getInput("price", 3);
	third.quantity = getInput("quantity", 3);

	subtotal = first.price * first.quantity + second.price * second.quantity + third.price * third.quantity;
	tax = subtotal * 5.5 / 100;

	cout << "Subtotal: $" << subtotal << endl;
	cout << "Tax: $" << tax << endl;
	cout << "Total: $" << tax + subtotal << endl;
}