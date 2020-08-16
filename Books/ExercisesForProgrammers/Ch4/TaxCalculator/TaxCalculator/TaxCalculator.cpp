#include <iostream>
constexpr auto STATE_TAX = 5.5;

using namespace std;

int main()
{
	double amount;
	string state;

	cout << "What is the order amount? ";
	cin >> amount;
	cout << "What is the state? ";
	cin >> state;
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