#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL));
    string contestant;
    vector<string> list;

    do {
        cout << "Enter a name: ";
        getline(cin, contestant);

        if(!contestant.empty())
            list.push_back(contestant);

    } while (!contestant.empty());

    cout << "The winner is " << list[rand() % list.size()];
}