#include "interest.h"

using namespace std;

int main()
{
    short months = 120;
    float interestRate = 0.01;
    double balance = 0, monthlyDeposit = 50;

    getValuesFromUser(balance, months, interestRate, monthlyDeposit);

    for(short i = 0; i < months; i++){
        balance = balance + balance*interestRate + monthlyDeposit;
        cout << "Month: " << i << " Balance: " << balance << endl;
    }
}

