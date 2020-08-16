#include <iostream>
#include <string>
#include <algorithm>

constexpr auto STATE_TAX = 5.5;

using namespace std;

double getDouble() {
	double input;

	cout << "What is the order amount? ";
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

string getString() {
	string input;

	cout << "What is the state? ";
	cin >> input;

	return input;
}

int main()
{
	double amount;
	string state;

	amount = getDouble();
	state = getString();

	std::for_each(state.begin(), state.end(), [](char& c) {c = ::toupper(c); });

	if (state == "WI") {
		cout << "The subtotal is $" << amount << endl;
		cout << "The tax is $" << amount/100*STATE_TAX << endl;
		
		amount += amount / 100 * STATE_TAX;
		cout << "The total is $" << amount << endl;
	}
	else {
		cout << "The total is $" << amount << endl;
	}
}