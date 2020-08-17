#include <iostream>
#include <algorithm>

using namespace std;

void promptForConversion(std::string& choice);
void convertTemperature(const string& question, const string& answer, const short& scale);

int main()
{
	string choice, question, answer;

	promptForConversion(choice);

	if (choice == "C") {
		question = "Fahrenheit";
		answer = "Celsius";
		convertTemperature(question, answer, 0);
	}
	else {
		question = "Celsius";
		answer = "Fahrenheit";
		convertTemperature(question, answer, 1);
	}
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

void convertTemperature(const string& question, const string& answer, const short& scale) {

	double temperature;

	cout << "Please enter the temperature in "<< question << ": ";
	cin >> temperature;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Only numbers allowed. Please try again" << endl;
		cin >> temperature;
	}

	switch (scale) {
		case 0:
			temperature = (temperature - 32) * 5 / 9;
			break;
		case 1:
			temperature = (temperature * 9 / 5) + 32;
			break;
		default:
			break;
	}

	cout << "The temperature in " << answer << " is: " << temperature << endl;

}
