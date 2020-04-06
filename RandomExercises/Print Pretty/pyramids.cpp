#include <iostream>
#include <vector>
#include <string>

using namespace std;



void printPyramid(){
    const short int base = 10;
    const char mark = '*';

    for (short int i = 0; i <= 10; i++)
    {
        for (short int j = 0; j < i; j++)
        {
            cout << mark;
        }
        cout << endl;
    }
}

void printReversePyramid(){
    const short int base = 10;
    const char mark = '*';

    for (short int i = 10; i >= 0; i--)
    {
        for (short int j = 0; j < i; j++)
        {
            cout << mark;
        }
        cout << endl;
    }
}

int main()
{
    printPyramid();
    printReversePyramid();
}
