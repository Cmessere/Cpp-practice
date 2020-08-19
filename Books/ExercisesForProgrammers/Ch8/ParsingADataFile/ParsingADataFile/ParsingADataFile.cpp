#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <tuple>
#include <algorithm>
# include "csv.h"

//Using _CRT_SECURE_NO_WARNINGS for csv library

using namespace std;

void getDataFromFile(vector<tuple<string, string, string>> &employee);
void outputDataAsTable(const vector<tuple<string, string, string>> &employee);
void sortBySalary(vector<tuple<string, string, string>> &employee);
bool salaryField(const tuple<string, string, string>& a, const tuple<string, string, string>& b);
void libraryApproach();

int main()
{
	vector<tuple<string, string, string>> employee;
	string choice;

	cout << "Do you want to use the 'basic' approach or 'library' approach? ";
	cin >> choice;
	std::for_each(choice.begin(), choice.end(), [](char& c) {c = ::toupper(c); });

	while (choice != "BASIC" && choice != "LIBRARY") {
		cout << "Sorry, choice not recognized. Please try again: ";
		cin >> choice;
		std::for_each(choice.begin(), choice.end(), [](char& c) {c = ::toupper(c); });
	}

	if (choice == "BASIC"){
		getDataFromFile(employee);
		sortBySalary(employee);
		outputDataAsTable(employee);
	}
	else {
		libraryApproach();
	}
}

void outputDataAsTable(const vector<tuple<string, string, string>>& employee)
{
	cout << setw(16) << right << "Last " << setw(15) << "First " << setw(15) << "Salary " << endl;

	for (int i = 0; i < employee.size(); i++) {
		auto t = employee[i];
		cout << setw(15) << right << get<0>(t) << setw(15) << get<1>(t) << setw(10) << "$" << get<2>(t) << endl;
	}
}

bool salaryField(const tuple<string, string, string>& a,const tuple<string, string, string>& b)
{
	return (get<2>(a) < get<2>(b));
}

void sortBySalary(vector<tuple<string, string, string>>& employee) {
	sort(employee.begin(), employee.end(), salaryField);
}

void getDataFromFile(vector<tuple<string, string, string>>& employee){
	string input;
	ifstream file;

	file.open("data.txt");

	if (!file.is_open()) {
		cout << "Could not open file!";
		exit(1);
	}

	while (getline(file, input)) {
		std::stringstream ss(input);
		std::string token;
		vector<string> tokenizedData;
		tuple<string, string, string> tuple;

		while (getline(ss, token, ',')) {
			tokenizedData.push_back(token);
		}

		std::get<0>(tuple) = tokenizedData[0];
		std::get<1>(tuple) = tokenizedData[1];
		std::get<2>(tuple) = tokenizedData[2];

		employee.push_back(tuple);
	}	
}

void libraryApproach()
{
	io::CSVReader<3> in("data.csv");
	std::string vendor; int size; double speed;
	in.read_header(io::ignore_extra_column, "last", "first", "salary");
	string last; string first; string salary;


	cout << setw(16) << right << "Last " << setw(15) << "First " << setw(15) << "Salary " << endl;


	while (in.read_row(last,first,salary)) {
		cout << setw(15) << right << last << setw(15) << first << setw(10) << "$" << salary << endl;
	}
}