#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void sortNames(vector<string> &names);
void inputNames();
void getNamesFromFile(vector<string>& names);
void getUserChoice(std::string& choice);
void printNames(const vector<string> &names);

int main()
{
	vector<string> names;
	string choice;


	getUserChoice(choice);

	if (choice == "OUTPUT") {
		getNamesFromFile(names);
		sortNames(names);
		printNames(names);
	}
	else {
		inputNames();
	}
}

void getUserChoice(std::string& choice)
{
	cout << "Do you want to insert names or output them? ";
	cin >> choice;

	std::for_each(choice.begin(), choice.end(), [](char& c) {c = ::toupper(c); });


	while (choice != "INSERT" && choice != "OUTPUT") {
		cout << "Not a valid choice. Please try again" << endl;
		getline(cin, choice);

		std::for_each(choice.begin(), choice.end(), [](char& c) {c = ::toupper(c); });
	}
}

void getNamesFromFile(vector<string>& names)
{
	string input;
	ifstream nameFile;
	cin.clear();

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

void inputNames() {
	string input;
	ofstream nameFile;

	cin.clear();
	cin.ignore();
	nameFile.open("names.txt", ios_base::app);
	
	while (true) {
		cout << "Enter a name, input 'done' to stop: ";
		getline(cin, input);

		if (input == "done")
			break;

		nameFile << endl <<  input;
	}
}