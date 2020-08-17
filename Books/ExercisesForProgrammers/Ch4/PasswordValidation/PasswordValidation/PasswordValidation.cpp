#include <iostream>

using namespace std;

int main()
{
	string password;

	cout << "What is the password? ";
	cin >> password;

	if (password == "abc$123") {
		cout << "Welcome!" << endl;
	}
	else {
		cout << "I don't know you" << endl;
	}
}