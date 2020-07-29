#include <iostream>
#include <string>

using namespace std;

int main()
{
    string prompt;
    cout << "Give me a word, I'll give you its length!" << endl;
    getline(cin, prompt);

	while (prompt.empty()){

        cout << "I need a word to give you a length, help me out here..." << endl;
        getline(cin, prompt);

	}
    cout << "The word " << prompt << " has " << prompt.length() << " letters in it.\nTry using it in a sentence!\n";

    return 0;
}