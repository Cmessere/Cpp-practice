#include <iostream>
using namespace std;

int main()
{
    string pointed = "Hey", *firstPointer, **secondPointer;

    firstPointer = &pointed;
    secondPointer = &firstPointer;

    cout << (*secondPointer)->size() << endl;
}