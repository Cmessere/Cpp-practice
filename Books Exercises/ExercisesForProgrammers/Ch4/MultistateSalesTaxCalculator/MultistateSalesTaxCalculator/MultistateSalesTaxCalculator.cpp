#include <iostream>
#include <string>
#include <algorithm>

constexpr auto STATE_TAX = 5.5;
constexpr auto IVA = 22;
constexpr auto EAU_CLAIRE_TAX = 0.005;
constexpr auto DUNN_TAX = 0.004;

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
	cin.ignore();
	return input;
}

string getString(const string question) {
	string input;

	cout << "What is the " << question << "? ";
	getline(std::cin,input);
	std::for_each(input.begin(), input.end(), [](char& c) {c = ::toupper(c); });

	return input;
}

int main()
{
	double amount, countyTax = 0;
	string state, county;

	amount = getDouble();
	state = getString("state");

	if (state == "WI" || state == "WINSCONSIN") {
		county = getString("county");

		if (county == "EAU CLAIRE")
			countyTax = amount / 100 * EAU_CLAIRE_TAX;
		if (county == "DUNN")
			countyTax = amount / 100 * DUNN_TAX;

		cout << "The subtotal is $" << amount << endl;
		cout << "The tax is $" << amount / 100 * STATE_TAX + countyTax << endl;

		amount += amount / 100 * STATE_TAX;
		cout << "The total is $" << amount << endl;
	}
	else if (state == "IT" || state == "ITALY") {
		cout << "The subtotal is $" << amount << endl;
		cout << "The tax is $" << amount / 100 * IVA << endl;

		amount += amount / 100 * IVA;
		cout << "The total is $" << amount << endl;
	}
	else {
		cout << "The total is $" << amount << endl;
	}
}