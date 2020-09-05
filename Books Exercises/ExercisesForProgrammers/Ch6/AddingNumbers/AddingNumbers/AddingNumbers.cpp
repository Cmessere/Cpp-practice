#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void getInt(int &input) {
	cout << "How many numbers do you want to add? ";
	cin >> input;
}

double getDouble(int &count) {
	double input;

	cout << "Enter a number: ";
	cin >> input;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		input = 0;
	}
	count++;
	return input;
}

int main()
{
	int numbersCount, counter = 0;
	vector<double> numbers;

	getInt(numbersCount);

	while (counter < numbersCount) {
		numbers.push_back(getDouble(counter));
	}

	cout << "The total is: " << std::accumulate(numbers.begin(), numbers.end(), 0);
}