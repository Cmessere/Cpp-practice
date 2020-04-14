#include <iostream>

using namespace std;

int main()
{
    short months = 120;
    float interestRate = 0.01;
    double balance = 0, montlyDeposit = 50;

    for(short i = 0; i < months; i++){
        balance = balance + balance*interestRate + montlyDeposit;
        cout << "Month: " << i << "Balance: " << balance << endl;
    }

}