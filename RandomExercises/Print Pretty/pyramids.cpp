#include <iostream>
#include <vector>
#include <string>

using namespace std;



void printPyramid(short int base, char mark){

    for (short int i = 0; i <= 10; i++)
    {
        for (short int j = 0; j < i; j++)
        {
            cout << mark;
        }
        cout << endl;
    }
}

void printReversePyramid(short int base, char mark){


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
    const short int base = 10;
    const char mark = '*';

    printPyramid(base, mark);
    printReversePyramid(base, mark);
}
