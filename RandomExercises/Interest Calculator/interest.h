#include <iostream>
#include <stdlib.h>     /* srand, rand */

using namespace std;

    void getValuesFromUser(double &balance, short &months, double &monthlyDeposit, float &interestRate, float upperInterestRate){
    cout << "Insert starting balance: ";
    cin >> balance;
    
    cout << "Insert number of months: ";
    cin >> months;
    
    if(interestRate == -2){
        cout << "Insert interest rate lower value: " ;
        cin >> interestRate;
        cout << "Insert interest rate upper value: " ;
        cin >> upperInterestRate;
    }
    else if(interestRate != -1){
        cout << "Insert interest rate (0.01 equals 1%): ";
        cin >> interestRate;
    }

    if(monthlyDeposit != -1){
        cout << "Insert monthly deposit rate: ";
        cin >> monthlyDeposit;
    }
}