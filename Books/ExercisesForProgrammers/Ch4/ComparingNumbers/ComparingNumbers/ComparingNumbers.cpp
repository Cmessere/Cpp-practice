#include <iostream>
#include <set>

using namespace std;

double getDouble(const short question) {
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
	double input, max = std::numeric_limits<double>::min();
	set<int> inputSet;

	for (short i = 0; i < 10; i++) {
		input = getDouble(i + 1);
		bool alreadyInserted = inputSet.find(input) != inputSet.end();

		while (alreadyInserted) {
			cout << "You already entered "<< input << endl;
			input = getDouble(i + 1);
			alreadyInserted = inputSet.find(input) != inputSet.end();
		}

		inputSet.insert(input);

		if (input > max) {
			max = input;
		}
	}
	
	cout << "The largest number is: " << max << endl;
}