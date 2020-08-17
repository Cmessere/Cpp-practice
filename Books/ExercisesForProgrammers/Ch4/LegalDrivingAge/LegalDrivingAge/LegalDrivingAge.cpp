#include <iostream>

using namespace std;

int main()
{
    unsigned short age;

    cout << "What is your age? ";
    cin >> age;

    age < 15 ? cout << "You are not old enough to legally drive." : cout << "You are old enough to legally drive.";
}