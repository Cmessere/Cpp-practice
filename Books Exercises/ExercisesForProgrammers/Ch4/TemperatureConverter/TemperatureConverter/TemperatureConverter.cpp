#include <iostream>
#include <algorithm>

using namespace std;

void promptForFirstScale(string& choice);
void convertTemperature(const string& question, const string& answer, const short& scale);
void getConversionFormula(const short& scale, double& temperature);
string promptForSecondScale(const string& question, const string& fistOption, const string& secondOption);

int main()
{
	string choice, question, firstOption, secondOption, answer;

	promptForFirstScale(choice);

	if (choice == "F") {
		question = "Fahrenheit";
		firstOption = "C";
		secondOption = "K";

		answer = promptForSecondScale(question, firstOption, secondOption);
		answer == "C" ? convertTemperature(question, answer, 0) : convertTemperature(question, answer, 1);
	}
	else if(choice == "C"){
		question = "Celsius";
		firstOption = "F";
		secondOption = "K";

		answer = promptForSecondScale(question, firstOption, secondOption);
		answer == "F" ? convertTemperature(question, answer, 2) : convertTemperature(question, answer, 3);
	}
	else {
		question = "Kelvin";
		firstOption = "F";
		secondOption = "C";

		answer = promptForSecondScale(question, firstOption, secondOption);
		answer == "F" ? convertTemperature(question, answer, 4) : convertTemperature(question, answer, 5);
	}
}

string promptForSecondScale(const string& question, const string& fistOption, const string& secondOption) {
	string answer;

	cout << "Do you want to convert " << question << " to " << fistOption << " or " << secondOption << "? ";
	cin >> answer;

	std::for_each(answer.begin(), answer.end(), [](char& c) { c = ::toupper(c); });

	while (answer != fistOption && answer != secondOption) {
		cout << "This is not a valid option, please try again." << endl;
		cin >> answer;
		std::for_each(answer.begin(), answer.end(), [](char& c) { c = ::toupper(c); });
	}

	return answer;
}

void promptForFirstScale(string& choice)
{
	cout << "Press C to convert to Celsius." << endl;
	cout << "Press F to convert to Fahrenheit." << endl;
	cout << "Press K to convert to Kelvin." << endl;
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

	getConversionFormula(scale, temperature);

	cout << "The temperature in " << answer << " is: " << temperature << endl;
}

void getConversionFormula(const short& scale, double& temperature)
{
	switch (scale) {
	case 0: //F 2 C
		temperature = (temperature - 32) * 5 / 9;
		break;
	case 1: // F 2 K
		temperature = (temperature - 32) * 5 / 9 + 273.15;
		break;
	case 2: // C 2 F
		temperature = (temperature * 9 / 5) + 32;
		break;
	case 3: // C 2 K
		temperature = (temperature + 273.15);
		break;
	case 4: // K 2 F
		temperature = (temperature - 273.15) * 9 / 5 + 32;
		break;
	case 5: // K 2 C
		temperature = (temperature - 273.15);
		break;
	default:
		break;
	}
}
