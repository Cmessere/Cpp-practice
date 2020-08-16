#include <iostream>

using namespace std;

int main()
{
	double rate, startingCapital, calculatedAmount;
	unsigned short investmentYears;

	cout << "Enter the principal: ";
	cin >> startingCapital;
	cout << "Enter the rate of interest: ";
	cin >> rate;
	cout << "Enter the number of years: ";
	cin >> investmentYears;

	calculatedAmount = startingCapital*(1 + rate / 100 * investmentYears);

	cout << "After " << investmentYears << " years at " << rate << "%, the investment will be worth $" << calculatedAmount;
}