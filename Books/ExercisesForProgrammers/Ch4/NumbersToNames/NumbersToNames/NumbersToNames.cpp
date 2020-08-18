#include <iostream>

using namespace std;

int main()
{
	short monthNumber;
	string monthName;

	cout << "Please enter the number of the month: ";
	cin >> monthNumber;

	while (monthNumber < 1 && monthNumber > 12) {
		cout << "Invalid number, please try again: ";
		cin >> monthNumber;
	}

	switch (monthNumber) {
		case 1:
			monthName = "January";
			break;
		case 2:
			monthName = "February";
			break;
		case 3:
			monthName ="March";
			break;
		case 4:
			monthName ="April";
			break;
		case 5:
			monthName ="May";
			break;
		case 6:
			monthName ="June";
			break;
		case 7:
			monthName ="July";
			break;
		case 8:
			monthName ="August";
			break;
		case 9:
			monthName ="September";
			break;
		case 10:
			monthName ="October";
			break;
		case 11:
			monthName ="November";
			break;
		case 12:
			monthName ="December";
			break;
	}
	cout << "The name of the month is " << monthName <<endl;
}