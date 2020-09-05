#include <iostream>
#include <regex>

using namespace std;

void getString(const string& question, string& input);
bool validateName(const string&  name, string& output);
bool validateSurname(const string& surname, string& output);
bool validateZIP(const string& zipCode, string& output);
bool validateId(const string& id, string& output);


void getString(const string& question, string& input) {
	cout << question;
	cin >> input;
}

bool validateName(const string& name, string& output) {
	if (name.size() == 0) {
		output += "The first name must be filled in.";
		return false;
	}
	regex regexp("[a-zA-Z]{2,}");

	if (!regex_match(name, regexp)) {
		output += "\"" + name + "\"is not a valid first name. It is too short.\n";
		return false;
	}

	return true;
}

bool validateSurname(const string& surname, string& output) {
	if (surname.size() == 0) {
		output += "The second name must be filled in.";
		return false;
	}
	regex regexp("[a-zA-Z]{2,}");

	if (!regex_match(surname, regexp)) {
		output += "\"" + surname + "\"is not a valid second name. It is too short.\n";
		return false;
	}

	return true;
}

bool validateZIP(const string& zipCode, string& output) {

	regex regexp("[0-9]+");

	if (!regex_match(zipCode, regexp)) {
		output += "The zipcode must be numeric\n";
		return false;
	}

	return true;
}

bool validateId(const string& id, string& output) {

	regex regexp("[a-zA-Z]{2}-[0-9]{4}");

	if (!regex_match(id, regexp)) {
		output += id + " is not a valid id.\n";
		return false;
	}

	return true;
}

int main()
{
	string name, surname, zipCode, id, output = "";
	bool nameValid = false, surnameValid = false, zipValid = false, idValid = false;

	while (!nameValid && surnameValid && zipValid && idValid) {
		output = "";

		getString("Enter the first name: ", name);
		getString("Enter the last name: ", surname);
		getString("Enter the ZIP code: ", zipCode);
		getString("Enter an employee ID (AA-1234): ", id);

		nameValid = validateName(name, output);
		surnameValid = validateSurname(surname, output);
		zipValid = validateZIP(zipCode, output);
		idValid = validateId(id, output);
	
		cout << output << endl;
	}

	cout << "There were no errors found.";
}