#include <iostream>
#include <vector>
#include <string>

using namespace std;



void printPyramid(short int base, char mark){

    for (short int i = 0; i <= base; i++)
    {
        for (short int j = 0; j < i; j++)
        {
            cout << mark;
        }
        cout << endl;
    }
}

void printReversePyramid(short int base, char mark){


    for (short int i = base; i >= 0; i--)
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
    short int base = 10;
    char mark = '*';

    cout << "insert base lenght:" << endl;
    cin >> base;

    cout << "insert fill character:" << endl;
    cin >> mark;

    printPyramid(base, mark);
    printReversePyramid(base, mark);
}
