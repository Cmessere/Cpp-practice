#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

short getShort(const string question);

void getSystem(std::string& system);

short getShort(const string question) {
	short input;

	cout << "What is your " << question << "? ";
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

int main()
{
	double BMI, height;
	short weight;
	string system;

	getSystem(system);

	height = getShort("height");
	weight = getShort("weight");

	BMI =  weight /(height/100 * height/100) ;

	if(system == "IMPERIAL")
		BMI = weight / (height * height )*703;

	cout << "Your BMI is " << BMI << endl;

	if (BMI < 18.5)
		cout << "You are underweight. You should see your doctor.";
	else if(BMI > 25)
		cout << "You are overweight. You should see your doctor.";
	else
		cout << "You are within the ideal weight range.";

}

void getSystem(std::string& system)
{
	cout << "Are you using Imperial or Metric system? ";
	cin >> system;

	std::for_each(system.begin(), system.end(), [](char& c) {c = ::toupper(c); });

	while (system != "IMPERIAL" && system != "METRIC") {
		cout << "Sorry, that is not a valid option. Please try again. " << endl;
		cin >> system;

		std::for_each(system.begin(), system.end(), [](char& c) {c = ::toupper(c); });
	}
}
