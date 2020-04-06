#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    printPyramid();
}

void printPyramid()
{
    const short int base = 10;
    const char mark = '*';

    for (short int i = 0; i < 10; i++)
    {
        for (short int j = 0; j < i; j++)
        {
            cout << mark;
        }
        cout << endl;
    }
}