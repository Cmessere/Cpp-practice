#include "interest.h"
#include <iostream>

using namespace std;

int main()
{
    short months = 120, interestOption;
    float interestRate = 0.01;
    double balance = 0, monthlyDeposit = 50;


    cout << "Select interest rate calculator: " << endl;
    cout << "1) Deposit only." << endl;
    cout << "2) Fixed Interest rate." << endl;
    cout << "3) Variable interest rate" << endl;
    cin >> interestOption;

    switch(interestOption){
        case 1:
            getValuesFromUser(balance, months, interestRate, monthlyDeposit);
            break;

        case 2:
            getValuesFromUser(balance, months, interestRate, monthlyDeposit);
            break;

        case 3:
            getValuesFromUser(balance, months, interestRate, monthlyDeposit);
            break;

        default:    
            getValuesFromUser(balance, months, interestRate, monthlyDeposit);
            break;
    }


    for(short i = 0; i < months; i++){
        balance = balance + balance*interestRate + monthlyDeposit;
        cout << "Month: " << i << " Balance: " << balance << endl;
    }
}

