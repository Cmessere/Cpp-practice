#include <iostream>
#include <map>
#include "NumbersToNames.h"

using namespace std;

int main()
{
	short monthNumber;
	string monthName, language;
	map<short, string> months, mesi, mois;

	initializeMonths(months);
	initializeMesi(mesi);
	initializeMois(mois);

	language = getString();

	cout << "Please enter the number of the month: ";
	cin >> monthNumber;

	while (monthNumber < 1 || monthNumber > 12) {
		cout << "Invalid number, please try again: ";
		cin >> monthNumber;
	}

	if (language == "EN") {
		monthName = months[monthNumber];
	}
	else if (language == "IT") {
		monthName = mesi[monthNumber];
	}
	else {
		monthName = mois[monthNumber];
	}

	cout << "The name of the month is " << monthName <<endl;
}