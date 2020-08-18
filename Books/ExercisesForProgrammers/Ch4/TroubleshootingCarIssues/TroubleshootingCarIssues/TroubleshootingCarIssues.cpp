#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

void initializeAcceptedAnswers(set<string> &acceptedAnswers);




bool getBool(const set<string> acceptedAnswers) {
	string answer;
	cin >> answer;

	std::for_each(answer.begin(), answer.end(), [](char& c) {c = ::toupper(c); });

	while (acceptedAnswers.find(answer) == acceptedAnswers.end()) {
		cout << "That is not a valid answer. Please try again" << endl;
		cin >> answer;
		std::for_each(answer.begin(), answer.end(), [](char& c) {c = ::toupper(c); });
	}

	if (answer == "Y" || answer == "YES") {
		return true;
	}

	return false;
}

int main()
{
	bool key, battery, click, crank, start, fuel;
	set<string> acceptedAnswers;

	initializeAcceptedAnswers(acceptedAnswers);

	cout << "Is the car silent when you turn the key ? ";
	key = getBool(acceptedAnswers);

	if (key) {
		cout << "Are the battery terminals corroded ? ";
		battery = getBool(acceptedAnswers);

		if (battery) {
			cout << "Clean terminals and try starting again." << endl;
		}
		else {
			cout << "Replace cables and try again." << endl;
		}
	}
	else {
		cout << "Does the car make a clicking noise ? ";
		click = getBool(acceptedAnswers);

		if(click)
			cout << "Replace the battery.";
		else {
			cout << "Does the car crank up but fail to start ? ";
			crank = getBool(acceptedAnswers);

			if(crank)
				cout << "Check spark plug connections." << endl;
			else {
				cout << "Does the engine start and then die ? ";
				start = getBool(acceptedAnswers);

				if (start) {
					cout << "Does your car have fuel injection ? ";
					fuel = getBool(acceptedAnswers);

					if (fuel)
						cout << "Get it in for service." << endl;
					else
						cout << "Check to ensure the choke is opening and closing." << endl;
				}
			}
		}
	}
}

void initializeAcceptedAnswers(set<string>& acceptedAnswers) {
	acceptedAnswers.insert("Y");
	acceptedAnswers.insert("N");
	acceptedAnswers.insert("YES");
	acceptedAnswers.insert("NO");
}