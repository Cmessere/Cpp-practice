#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <list>

using namespace std;

int shakeBall() {
	srand(time(NULL));

	return rand() % 4;
}

int main()
{
	list<string> answers = { "No" , "Yes", "Maybe", "Ask again later." };
	string question;


	auto it = answers.begin();

	cout << "What's your question? ";
	cin >> question;

	advance(it, shakeBall());

	cout << *it;
}