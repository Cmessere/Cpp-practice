#include <iostream>
#include <list>
#include <string>
#include <random>
#include <time.h>

using namespace std;

void getInput(const string& question, int& input);
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
	
	int random = distribution(engn);

	auto it = list.begin();
	advance(it , random);
	
	return *it;
}

string getRandomDigit() {
	random_device engn;
	uniform_int_distribution<size_t> distribution(0, 10);
	
	//int random = distribution(engn);

	return std::to_string(distribution(engn));
}


int main()
{
	int length, specialCount, numberCount;
	list<string> symbols = { "%", "$", "!", "&", "?" };
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

	random_shuffle(password.begin(), password.end());
	cout << "Your password is: " << endl << password;

}