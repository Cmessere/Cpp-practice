#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

vector<int> filterEvenNumbers(const vector<int> &unfiltered);

void getInputs(std::vector<int>& numbers);

void outputEvens(std::vector<int>& evens);

int main()
{
	vector<int> numbers, evens;

	getInputs(numbers);

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

void getInputs(std::vector<int>& numbers)
{
	cout << "Getting numbers from file: ";
	ifstream inFile;
	string number;

	inFile.open("numbers.txt");

	if (!inFile.is_open()) {
		cout << "Could not open file.";
		exit(1);
	}

	while (getline(inFile, number)) {
		cout << number << " ";
		numbers.push_back(stoi(number));
	}

	cout << endl;
}

vector<int> filterEvenNumbers(const vector<int> &unfiltered) {
	vector<int> filtered;

	for (auto i : unfiltered) {
		if (i % 2 == 0)
			filtered.push_back(i);
	}

	return filtered;
}
