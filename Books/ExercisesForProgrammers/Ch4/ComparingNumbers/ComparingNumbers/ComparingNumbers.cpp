#include <iostream>

using namespace std;

double getDouble(const string question) {
	double input;

	cout << "Enter the "<< question << " number: ";
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
	double first, second, third, max = std::numeric_limits<double>::min();
	
	first = getDouble("first");

	second = getDouble("second");
	while (second == first) {
		cout << "You already entered this number." << endl;
		second = getDouble("second");
	}

	third = getDouble("third");
	while (third == first || third == second) {
		cout << "You already entered this number." << endl;
		third = getDouble("third");
	}

	if (first == second || second == third || third == first) {
		cout << "One of the numbers is equal to the others, exiting..";
		return 1;
	}

	if(first > max)
		max = first;
	if(second > max)
		max = second;
	if(third > max)
		max = third;
	
	cout << "The largest number is: " << max << endl;
}