#include <iostream>

using namespace std;

int main()
{
    string noun, verb, adjective, adverb;

    cout << "Enter a noun :" << endl;
    cin >> noun;
    cout << "Enter a verb :" << endl;
    cin >> verb;
    cout << "Enter an adjective :" << endl;
    cin >> adjective;
    cout << "Enter an adverb :" << endl;
    cin >> adverb;

    cout << "Do you " << verb << " your " << adjective << " " << noun << " "  << adverb << "? That's hilarious!" << endl;
}