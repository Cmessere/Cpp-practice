#include <iostream>
using namespace std;

int main()
{
	bool notFound = true;
	short tries = 1, lower = 1, higher = 100;
	cout << "Pick a number between 1 and 100, I will guess it!" << endl;

	system("pause");

	while (notFound) {
		string answer;


		cout << "Is this your number: " << (lower + higher) / 2 << "?" << endl;
		cout << "If it is type 'yes', or tell me if it's 'low' or 'high'" << endl;
		cin >> answer;

		if (answer == "yes" || answer == "y" || answer == "Y") {
			cout << "Nice! It took " << tries << " tries!" << endl;
			notFound = false;
		}
		else {
			tries++;

			if (answer == "high" || answer == "High")
				lower = (lower + higher) / 2;
			else
				higher = (lower + higher) / 2;
		}

		if (higher - 1 == lower || lower + 1 == higher) {
			cout << "Hey! Don't cheat!" << endl;
			notFound = false;
		}
	}
}