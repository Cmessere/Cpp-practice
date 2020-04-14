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

void depositOnly(double &balance, short &months, double &monthlyDeposit, float &interestRate){
    getValuesFromUser(balance, months, monthlyDeposit, interestRate=-1, 0);
    
    for(short i = 0; i < months; i++){
        balance += monthlyDeposit;
        cout << "Month: " << i << " Balance: " << balance << endl;
    }
}
void fixedRateInterest(double &balance, short &months, double &monthlyDeposit, float &interestRate){
    getValuesFromUser(balance, months, monthlyDeposit, interestRate, 0);
    
    for(short i = 0; i < months; i++){
        balance = balance + monthlyDeposit + balance*interestRate;
        cout << "Month: " << i << " Balance: " << balance << endl;
    }
}

void variableRateInterest(double &balance, short &months, double &monthlyDeposit, float &interestRate, float &upperInterestRate){
    getValuesFromUser(balance, months, monthlyDeposit, interestRate = -2, upperInterestRate);
    
    float randomInterestRate = (upperInterestRate*100 + interestRate*100)/((upperInterestRate*100 - interestRate*100));

    for(short i = 0; i < months; i++){
        balance = balance + monthlyDeposit + balance*(randomInterestRate/100);
        cout << "Month: " << i << " Balance: " << balance << endl;
    }
}