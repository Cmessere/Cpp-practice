#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <tuple>

using namespace std;

void getDataFromFile(vector<tuple<string, string, string>> &employee);
void outputDataAsTable(vector<tuple<string, string, string>> &employee);


int main()
{
	vector<tuple<string, string, string>> employee;

	vector<string> firstNames, lastNames, salaries;
	getDataFromFile(employee);
	outputDataAsTable(employee);
}

void outputDataAsTable(vector<tuple<string, string, string>>& employee)
{
	cout << setw(16) << right << "Last " << setw(15) << "First " << setw(15) << "Salary " << endl;

	for (int i = 0; i < employee.size(); i++) {
		auto t = employee[i];
		cout << setw(15) << right << get<0>(t) << setw(15) << get<1>(t) << setw(10) << "$" << get<2>(t) << endl;
	}
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
