#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void sortNames(vector<string> &names);
void getNamesFromFile(vector<string>& names);
void printNames(const vector<string> &names);

int main()
{
	vector<string> names;

	getNamesFromFile(names);
	sortNames(names);
	printNames(names);
}

void getNamesFromFile(vector<string>& names)
{
	string input;
	ifstream nameFile;

	nameFile.open("names.txt");

	if (!nameFile.is_open()) {
		cout << "Could not open file";
		exit(1);
	}

	while (getline(nameFile, input)) {
		names.push_back(input);
	}
}

void sortNames(vector<string> &names) {
	sort(names.begin(), names.end());
}

void printNames(const vector<string> &names) {
	cout << "Total of " << names.size() << " names" << endl;

	for (auto n : names) {
		cout << n << endl;
	}
}
