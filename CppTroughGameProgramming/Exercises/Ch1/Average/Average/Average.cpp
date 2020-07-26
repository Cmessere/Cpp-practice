#include <iostream>
using namespace std;

int main()
{
    bool going = true;

    while (going) {
        int average = 0;
        char prompt;
        for (unsigned short int i = 0; i < 3; i++) {
            int value;

            cout << "Insert an integer: ";
            cin >> value;
            average += value;
        }
        cout << "The average is " << average/3 << endl;
        cout << "Do you want to keep going? (y/n)" << endl;
        cin >> prompt;

        going = (prompt == 'y'  || prompt == 'Y' ) ? true : false;
    }
}