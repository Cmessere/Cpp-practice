#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> filterEvenNumbers(const vector<int> &unfiltered);

void getInputs(std::string& rawInput, std::vector<std::string>& stringNumbers, std::vector<int>& numbers);

void outputEvens(std::vector<int>& evens);

int main()
{
	string rawInput;
	vector<int> numbers, evens;
	vector<string> stringNumbers;

	getInputs(rawInput, stringNumbers, numbers);

	evens = filterEvenNumbers(numbers);

	outputEvens(evens);
}

void outputEvens(std::vector<int>& evens)
{
	cout << "The even numbers are: ";
	for (auto i : evens) {
		cout << i << " ";
	}
}

void getInputs(std::string& rawInput, std::vector<std::string>& stringNumbers, std::vector<int>& numbers)
{
	cout << "Enter a list of numbers, separated by spaces (space enter to stop): ";

	while (cin.peek() != '\n')
	{
		getline(cin, rawInput, ' ');
		stringNumbers.push_back(rawInput);
	}

	for (auto s : stringNumbers) {
 		numbers.push_back(stoi(s));
	}
}

vector<int> filterEvenNumbers(const vector<int> &unfiltered) {
	vector<int> filtered;

	for (auto i : unfiltered) {
		if (i % 2 == 0)
			filtered.push_back(i);
	}

	return filtered;
}
