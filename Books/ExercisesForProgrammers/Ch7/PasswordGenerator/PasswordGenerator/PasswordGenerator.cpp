#include <iostream>
#include <list>
#include <string>
#include <random>
#include <time.h>
#include <Windows.h> 
#include <winuser.h>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>

using namespace std;

void getInput(const string& question, int& input);
void convertVowelsToDigits(string& password, const list<string> vowels);
void generatePassword();
void copyPasswordToClipboard(int& selectedOption, int iterations, std::vector<std::string>& passwords);
string getRandomChar(const list<string> & list);
string getRandomDigit();
void toClipboard(const string& s);



int main()
{
	generatePassword();
}

void generatePassword()
{
	int length, specialCount, numberCount, iterations, selectedOption;
	list<string> symbols = { "%", "$", "!", "&", "?" };
	list<char> vowels = { 'a', 'e', 'i', 'o', 'u' };
	list<string> chars = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l",
		"m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" };

	string password;
	vector<string> passwords;

	getInput("What is the minimum length? ", length);
	getInput("How many special characters? ", specialCount);
	getInput("How many numbers? ", numberCount);
	getInput("How many variants do you want? ", iterations);

	for (int k = 0; k < iterations; k++) {
		password = "";

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
		passwords.push_back(password);

		cout << "Your password number " << k+1 << " is: " << endl << password << endl << endl;
	}	

	copyPasswordToClipboard(selectedOption, iterations, passwords);
}

void copyPasswordToClipboard(int& selectedOption, int iterations, std::vector<std::string>& passwords)
{
	cout << "Which password do you want copied? ";
	cin >> selectedOption;

	while (cin.fail() || (selectedOption <= 0 || selectedOption > iterations)) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Sorry, that is not a valid option. Please try again: ";
		cin >> selectedOption;
	}

	cout << "copying...";
	toClipboard(passwords[selectedOption - 1]);
}

void getInput(const string& question, int& input) {
	cout << question;
	cin >> input;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Only numbers allowed. Please try again" << endl;
		cin >> input;
	}
}

string getRandomChar(const list<string>& list) {
	random_device engn;
	uniform_int_distribution<size_t> distribution(0, list.size() - 1);

	auto it = list.begin();
	advance(it, distribution(engn));

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

void toClipboard(const string& s) {
	OpenClipboard(0);
	EmptyClipboard();
	HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, s.size());
	if (!hg) {
		CloseClipboard();
		return;
	}
	memcpy(GlobalLock(hg), s.c_str(), s.size());
	GlobalUnlock(hg);
	SetClipboardData(CF_TEXT, hg);
	CloseClipboard();
	GlobalFree(hg);
}