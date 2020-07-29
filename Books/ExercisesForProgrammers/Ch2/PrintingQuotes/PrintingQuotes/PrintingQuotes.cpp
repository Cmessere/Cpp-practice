#include <iostream>
#include <string>
using namespace std;

int main()
{
    string quote, author;
    cout << "Tell me a quote!\n";
    getline(cin, quote);
    cout << "Oh, interesting, and who said that?\n";
    getline(cin, author);

    cout << author << " says, \"" << quote << "\"\n";
}
