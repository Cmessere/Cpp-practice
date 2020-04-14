#include "interest.h"
#include <iostream>

using namespace std;

int main()
{
    short months, interestOption;
    float interestRate;
    double balance, monthlyDeposit;


    cout << "Select interest rate calculator: " << endl;
    cout << "1) Deposit only." << endl;
    cout << "2) Fixed Interest rate." << endl;
    cout << "3) Variable interest rate" << endl;
    cin >> interestOption;

    switch(interestOption){
        case 1:
            depositOnly(balance, months, monthlyDeposit, interestRate);
            break;

        case 2:
            fixedRateInterest(balance, months, monthlyDeposit, interestRate);
            break;

        case 3:
            getValuesFromUser(balance, months, monthlyDeposit, interestRate);
            break;

        default:    
            getValuesFromUser(balance, months, monthlyDeposit, interestRate);
            break;
    }
}

