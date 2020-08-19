#include <iostream>
#include <list>
#include <string>
#include <random>
#include <time.h>

using namespace std;

void getInput(const string& question, int& input);
void convertVowelsToDigits(string& password, const list<string> vowels);
string getRandomChar(const list<string> & list);
string getRandomDigit();

void getInput(const string& question, int& input) {
	cout << question;
	cin >> input;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Only numbers allowed. Please try again" << endl;
		cin >> input;
	}
}

string getRandomChar(const list<string> &list) {
	random_device engn;
	uniform_int_distribution<size_t> distribution(0, list.size()-1);
	
	auto it = list.begin();
	advance(it , distribution(engn));
	
	return *it;
}

string getRandomDigit() {
	random_device engn;
	uniform_int_distribution<size_t> distribution(0, 10);
	
	return std::to_string(distribution(engn));
}

void convertVowelsToDigits(string& password, const list<char> vowels) {
	for (int i = 0; i < password.size(); i++) {
		auto it = std::find(vowels.begin(), vowels.end(), password[i]);

		if (it != vowels.end()) {
			password.replace(i, 1, getRandomDigit());
		}
	}
}

int main()
{
	int length, specialCount, numberCount;
	list<string> symbols = { "%", "$", "!", "&", "?" };
	list<char> vowels = { 'a', 'e', 'i', 'o', 'u' };
	list<string> chars = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l",
		"m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

	string password = "";

	getInput("What is the minimum length? ", length);
	getInput("How many special characters? ", specialCount);
	getInput("How many numbers? ", numberCount);

	for (int i = 0; i < specialCount; i++) {
		password += getRandomChar(symbols);
	}

	for (int i = 0; i < numberCount; i++) {
		password += getRandomDigit();
	}

	for (int i = 0; i < length - specialCount - numberCount; i++) {
		password += getRandomChar(chars);
	}

	convertVowelsToDigits(password, vowels);

	random_shuffle(password.begin(), password.end());
	cout << "Your password is: " << endl << password;
}