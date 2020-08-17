#include <iostream>
#include <algorithm>

using namespace std;

void fahrenheitToCelsius();
void promptForConversion(std::string& choice);
void celsiusToFahrenheit();

int main()
{
	string choice;

	promptForConversion(choice);

	choice == "C" ? fahrenheitToCelsius() : celsiusToFahrenheit();
}

void promptForConversion(std::string& choice)
{
	cout << "Press C to convert from Fahrenheit to Celsius." << endl;
	cout << "Press F to convert from Celsius to Fahrenheit." << endl;
	cout << "Your choice: ";
	cin >> choice;

	std::for_each(choice.begin(), choice.end(), [](char& c) { c = ::toupper(c); });

	while (choice != "C" && choice != "F") {
		cout << "This is not a valid option, please try again." << endl;
		cin >> choice;
		std::for_each(choice.begin(), choice.end(), [](char& c) { c = ::toupper(c); });
	}
}

void fahrenheitToCelsius() {
	double temperature;

	cout << "Please enter the temperature in Fahrenheit: ";
	cin >> temperature;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Only numbers allowed. Please try again" << endl;
		cin >> temperature;
	}

	temperature = (temperature - 32) * 5 / 9;

	cout << "The temperature in celsius is " << temperature << endl;
}

void celsiusToFahrenheit() {
	double temperature;

	cout << "Please enter the temperature in Celsius: ";
	cin >> temperature;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Only numbers allowed. Please try again" << endl;
		cin >> temperature;
	}

	temperature = (temperature * 9/5) + 32;

	cout << "The temperature in Fahrenheit is " << temperature << endl;
}