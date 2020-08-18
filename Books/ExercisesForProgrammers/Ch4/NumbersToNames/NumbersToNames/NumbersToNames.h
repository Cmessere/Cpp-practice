#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

void initializeMonths(map<short, string> &map);
void initializeMesi(map<short, string> &map);
void initializeMois(map<short, string> &map);
string getString();

void initializeMonths(map<short, string> &map) {
	map[1] = "January";
	map[2] = "February";
	map[3] = "March";
	map[4] = "April";
	map[5] = "May";
	map[6] = "June";
	map[7] = "July";
	map[8] = "August";
	map[9] = "September";
	map[10] = "October";
	map[11] = "November";
	map[12] = "December";
}

void initializeMesi(map<short, string> &map) {
	map[1] = "Gennaio";
	map[2] = "Febbraio";
	map[3] = "Marzo";
	map[4] = "Aprile";
	map[5] = "Maggio";
	map[6] = "Giugno";
	map[7] = "Luglio";
	map[8] = "Agosto";
	map[9] = "Settembre";
	map[10] = "Ottobre";
	map[11] = "Novembre";
	map[12] = "Dicembre";
}

void initializeMois(map<short, string> &map) {
	map[1] = "Janvier";
	map[2] = "Fevrier";
	map[3] = "Mars";
	map[4] = "Avril";
	map[5] = "Mai";
	map[6] = "Juin";
	map[7] = "Juillet";
	map[8] = "Aout";
	map[9] = "Septembre";
	map[10] = "Octobre";
	map[11] = "Novembre";
	map[12] = "Décembre";
}

string getString() {
	string input;

	cout << "Select language En, It or Fr" << endl;
	cin >> input;

	std::for_each(input.begin(), input.end(), [](char& c) {c = ::toupper(c); });

	while (input != "EN" && input != "IT" && input != "FR") {
		cout << "That is not a valid option, please try again." << endl;
		cin >> input;

		std::for_each(input.begin(), input.end(), [](char& c) {c = ::toupper(c); });
	}

	return input;
}