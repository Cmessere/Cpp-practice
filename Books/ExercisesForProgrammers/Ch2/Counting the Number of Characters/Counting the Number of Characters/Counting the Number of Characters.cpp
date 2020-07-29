#include <iostream>
using namespace std;

int main()
{
    string prompt;

    cout << "Give me a word, I'll give you its length!" << endl;
    cin >> prompt;
    cout << "The word " << prompt << " has " << prompt.length() << " letters in it.\nTry using it in a sentence!\n";

}