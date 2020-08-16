#include <iostream>

using namespace std;

int main()
{
    double euro, rate;

    cout << "How many euros are you exchanging? ";
    cin >> euro;
    cout << "What is the exchange rate? ";
    cin >> rate;

    cout << euro << " euros at an exchange rate of " << rate << " is " << euro * rate / 100 << " dollars.\n";
}