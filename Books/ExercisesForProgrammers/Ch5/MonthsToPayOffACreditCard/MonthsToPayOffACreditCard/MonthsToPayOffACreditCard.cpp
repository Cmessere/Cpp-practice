#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

void getDouble(const string& question, double& input);

void getDouble(const string& question, double& input) {
	cout << question;
	cin >> input;

	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Only numbers allowed. Please try again" << endl;
		cin >> input;
	}
}

double calculateMonthsUntilPaidOff( double& balance,  double& APR,  double& monthlyRate) {
	double numerator, denominator;

	numerator = log(monthlyRate / (monthlyRate - (balance * (APR / 12))));
	denominator = log(1 + APR / 12);

	return (numerator / denominator);
}

double calculateRateUntilPaidOff(double& balance, double& APR, double& months) {
	double numerator, denominator;

	numerator = balance * (APR / 12);
	denominator = 1 -  pow(1 +APR / 12, -months);

	return (numerator / denominator);
}

void calculatePay() {
	double balance, APR, monthlyRate, months;

	getDouble("What is your balance? ", balance);
	getDouble("What is the APR on the card (as a percent)? ", APR);
	getDouble("What is the number of months? ", months);

	APR /= 100;

	monthlyRate = calculateRateUntilPaidOff(balance, APR, months);

	cout << "It will take you " << ceil(monthlyRate) << "per month to repay the card in "<< months << " months.";
}
void calculateMonths() {
	double balance, APR, monthlyRate, months;

	getDouble("What is your balance? ", balance);
	getDouble("What is the APR on the card (as a percent)? ", APR);
	getDouble("What is the monthly payment you can make? ", monthlyRate);

	APR /= 100;

	months = calculateMonthsUntilPaidOff(balance, APR, monthlyRate);

	cout << "It will take you " << ceil(months) << " to repay the card.";
}

int main()
{
	string choice;

	cout << "Would you like to calculate 'months' untill payoff or amount to 'pay' per month? ";
	cin >> choice;

	std::for_each(choice.begin(), choice.end(), [](char& c) {c = ::toupper(c); });

	while (choice != "MONTHS" && choice != "PAY") {
		cout << "That is not a valid option, please try again." << endl;
		cin >> choice;

		std::for_each(choice.begin(), choice.end(), [](char& c) {c = ::toupper(c); });

	}

	if (choice == "MONTHS")
		calculateMonths();
	else
		calculatePay();
}