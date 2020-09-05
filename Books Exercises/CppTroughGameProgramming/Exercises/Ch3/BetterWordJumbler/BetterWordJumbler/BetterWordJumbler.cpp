#include <iostream>
#include <time.h>
#include "BetterWordJumbler.h"
using namespace std;

int main()
{
	enum fields {WORD, HINT, NUM_FIELDS};
	const int NUM_WORDS = 10;
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
		{"teeth", "They rest and and can go into gums"},
		{"rainbow", "Dark side of the moon"},
		{"azeroth", "The sleeping titan of world of warcraft"},
		{"kerrigan", "Bow to the queen o'blades!"},
		{"omega", "It comes last, after the alpha"},
		{"wolf", "Howls at the moon"},
		{"firefly", "when in doubt, follow the lights"},
		{"water", "you're made of it"},
		{"monster", "energy drink? collector of laughs?"},
		{"starship","it's ment to fly"}
	};

	srand(static_cast<unsigned int>(time(0)));
	int choice = (rand() % NUM_WORDS);
	string theWord = WORDS[choice][WORD]; 
	string theHint = WORDS[choice][HINT]; 

	string jumble = theWord; 
	int length = jumble.size();

	JumbleWord(length, jumble);

	return GameCycle(jumble, theWord, theHint);
}

int GameCycle(std::string& jumble, std::string& theWord, std::string& theHint)
{
	bool hintUsed = false;
	cout << "\t\t\tWelcome to Word Jumble!\n\n";
	cout << "Unscramble the letters to make a word.\n";
	cout << "Enter 'hint' for a hint.\n";
	cout << "Enter 'quit' to quit the game.\n\n";
	cout << "The jumble is: " << jumble;
	string guess;
	cout << "\n\nYour guess: ";
	cin >> guess;

	while ((guess != theWord) && (guess != "quit"))
	{
		if (guess == "hint")
		{
			cout << theHint;
			hintUsed = true;
		}
		else
		{
			cout << "Sorry, that\'s not it.";
		}
		cout << "\n\nYour guess: ";
		cin >> guess;
	}
	if (guess == theWord)
	{
		cout << "\nThat\'s it! You guessed it!\n";
	}

	if (hintUsed) {
		cout << "your score, with hint penalty, is: " << (theWord.length() * 100) / 2 << endl;
	}
	else {
		cout << "You did not use a hint! Your score is: " << theWord.length() * 100 << endl;
	}
	
	cout << "\nThanks for playing.\n";
	return 0;
}

void JumbleWord(int length, std::string& jumble)
{
	for (int i = 0; i < length; ++i)
	{
		int index1 = (rand() % length);
		int index2 = (rand() % length);
		char temp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;
	}
}
