#include <iostream>

using namespace std;

int main()
{
    short age;

    cout << "What is your age? ";
    cin >> age;

    while (cin.fail() || age < 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Only positive numbers allowed. Please try again" << endl;
        cin >> age;
    }
    
    age < 15 ? cout << "You are not old enough to legally drive." : cout << "You are old enough to legally drive.";
}