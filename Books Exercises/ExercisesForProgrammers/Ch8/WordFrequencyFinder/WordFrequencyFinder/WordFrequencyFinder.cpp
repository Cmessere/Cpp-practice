#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{
	map<string, int> occurrences;
	typedef pair<string, int> pair;
	vector<pair> vector;

	ifstream inputFile;
	string word;

	inputFile.open("input.txt");

	if (!inputFile.is_open()) {
		cout << "Could not open file!";
		exit(1);
	}

	while (inputFile >> word) {
		std::for_each(word.begin(), word.end(), [](char& c) {c = ::tolower(c); });

		map<string, int>::iterator it = occurrences.find(word);
		if (it != occurrences.end())
		{
			occurrences[word]++;
		}
		else {
			occurrences[word] = 1;
		}

	}

	copy(occurrences.begin(), occurrences.end(), back_inserter<std::vector<pair>>(vector));

	std::sort(vector.begin(), vector.end(),[](const pair& l, const pair& r) {
				return l.second > r.second;
		});

	for (auto i : vector) {
		cout << i.first << ": " << i.second <<endl;
	}
}