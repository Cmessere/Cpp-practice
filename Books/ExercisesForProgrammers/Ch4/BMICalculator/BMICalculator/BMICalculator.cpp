#include <iostream>
#include <string>

using namespace std;

short getShort(const string question);

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

	cout << "Using metric system." << endl;
	height = getShort("height");
	weight = getShort("weight");

	BMI =  weight /(height/100 * height/100) ;

	cout << "Your BMI is " << BMI << endl;

	if (BMI < 18.5)
		cout << "You are underweight. You should see your doctor.";
	else if(BMI > 25)
		cout << "You are overweight. You should see your doctor.";
	else
		cout << "You are within the ideal weight range.";

}