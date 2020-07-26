// Hangman
// The classic game of hangman

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>
#include "BetterHangman.h"

using namespace std;

char getGuess();

void correctGuess(char guess, const std::string& THE_WORD, std::string& soFar);

int main()
{
    // set-up
    const int MAX_WRONG = 8;  // maximum number of incorrect guesses allowed

    vector<string> words;  // collection of possible words to guess
    words.push_back("GUESS");
    words.push_back("HANGMAN");
    words.push_back("DIFFICULT");

    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(words.begin(), words.end());
    const string THE_WORD = words[0];            // word to guess
    int wrong = 0;                               // number of incorrect guesses
    string soFar(THE_WORD.size(), '-');          // word guessed so far
    string used = "";                            // letters already guessed

    cout << "Welcome to Hangman.  Good luck!\n";

    // main loop
    while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
    {
        cout << "\n\nYou have " << (MAX_WRONG - wrong);
        cout << " incorrect guesses left.\n";
        cout << "\nYou've used the following letters:\n" << used << endl;
        cout << "\nSo far, the word is:\n" << soFar << endl;

        char guess = getGuess();
        while (used.find(guess) != string::npos)
        {
            cout << "\nYou've already guessed " << guess << endl;
            guess = getGuess();
        }

        used += guess;

        if (THE_WORD.find(guess) != string::npos)
        {
            correctGuess(guess, THE_WORD, soFar);
        }
        else
        {
            cout << "Sorry, " << guess << " isn't in the word.\n";
            ++wrong;
        }
    }

    // shut down
    if (wrong == MAX_WRONG)
        cout << "\nYou've been hanged!";
    else
        cout << "\nYou guessed it!";

    cout << "\nThe word was " << THE_WORD << endl;

    return 0;
}

void correctGuess(char guess, const std::string& THE_WORD, std::string& soFar)
{
    cout << "That's right! " << guess << " is in the word.\n";

    // update soFar to include newly guessed letter
    for (unsigned int i = 0; i < THE_WORD.length(); ++i)
    {
        if (THE_WORD[i] == guess)
        {
            soFar[i] = guess;
        }
    }
}

char getGuess()
{
    char guess;
    cout << "\n\nEnter your guess: ";
    cin >> guess;
    return guess = toupper(guess); //make uppercase since secret word in uppercase
}
