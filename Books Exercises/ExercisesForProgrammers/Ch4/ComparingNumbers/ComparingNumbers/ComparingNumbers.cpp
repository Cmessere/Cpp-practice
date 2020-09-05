#include <iostream>
#include <set>

using namespace std;

double getDouble(const short question, bool &keepAsking) {
	double input;

	cout << "Enter the "<< question << " number: ";
	cin >> input;

	if (input == -1)
		keepAsking = false;

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
	short numberCount = 0;
	bool keepAsking = true;

	cout << "Keep adding numbers, insert -1 to stop." << endl;

	while(keepAsking){
		input = getDouble(numberCount + 1, keepAsking);
		bool alreadyInserted = inputSet.find(input) != inputSet.end();
		
		while (alreadyInserted) {
			cout << "You already entered "<< input << endl;
			input = getDouble(numberCount + 1, keepAsking);
			alreadyInserted = inputSet.find(input) != inputSet.end();
		}

		inputSet.insert(input);

		if (input > max) {
			max = input;
		}

		numberCount++;
	}
	
	cout << "The largest number is: " << max << endl;
}