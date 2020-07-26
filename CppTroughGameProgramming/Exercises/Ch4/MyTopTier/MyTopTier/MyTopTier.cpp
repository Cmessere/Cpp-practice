#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void addItem(vector<string> &top) {
	string newItem;
	cout << "Type what you would like to add to the list!" << endl;
	cin >> newItem;

	top.push_back(newItem);
}

void removeItem(vector<string>& top) {
	string newItem;
	cout << "Type what you would like to remove from the list!" << endl;
	cin >> newItem;

	auto itr = std::find(top.begin(), top.end(), newItem);

	if (itr != top.end())
		top.erase(itr);
}

void printList(vector<string>& top) {
	cout << "Showing all entris: " << endl;

	for (auto& element : top) {
		cout << element << endl;
	}
}

int main()
{
	bool running = true;
	vector<string> myTopGames;

	while (running) {
		string action;

		cout << "What would you like to do?" << endl;
		cout << "You can either 'Add' or 'Remove' an element, or 'Show' all entries." << endl;
		cout << "If you wish to end type 'Stop'\n" << endl;
		cin >> action;

		std::transform(action.begin(), action.end(), action.begin(), ::toupper);

		if (action == "STOP")
			running = false;
		if (action == "SHOW")
			printList(myTopGames);
		else {
			action == "ADD" ? addItem(myTopGames) : removeItem(myTopGames);
		}

	}
}

