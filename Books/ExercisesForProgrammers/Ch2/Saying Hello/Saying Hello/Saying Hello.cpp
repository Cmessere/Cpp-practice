#include <iostream>
using namespace std;

int main()
{
    string name;

    cout << "Hey, what's your name?" << endl;
    cout << "Hello " << *istream_iterator<string>(cin) << ", what's up?" << endl;
}

