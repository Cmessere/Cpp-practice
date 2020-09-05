#include <iostream>

using namespace std;

int askForNumber(string prompt = "default");

int main()
{
	int number;
	number = askForNumber();
}

int askForNumber(string prompt) {
	int number;
	cout << "Give me a number!" << endl;
	cin >> number;
	return number;
}
