#include <iostream>
using namespace std;

void getValuesFromUser(double &balance, short &months, double &monthlyDeposit, float &interestRate){
    cout << "Insert starting balance: ";
    cin >> balance;
    
    cout << "Insert number of months: ";
    cin >> months;
    
    if(interestRate != -1){
        cout << "Insert interest rate (0.01 equals 1%): ";
        cin >> interestRate;
    }

    if(monthlyDeposit != -1){
        cout << "Insert monthly deposit rate: ";
        cin >> monthlyDeposit;
    }
}

void depositOnly(double &balance, short &months, double &monthlyDeposit, float &interestRate){
    getValuesFromUser(balance, months, monthlyDeposit, interestRate=-1);
    
    for(short i = 0; i < months; i++){
        balance += monthlyDeposit;
        cout << "Month: " << i << " Balance: " << balance << endl;
    }
}
void fixedRateInterest(double &balance, short &months, double &monthlyDeposit, float &interestRate){
    getValuesFromUser(balance, months, monthlyDeposit, interestRate);
    
    for(short i = 0; i < months; i++){
        balance = balance + monthlyDeposit + balance*interestRate;
        cout << "Month: " << i << " Balance: " << balance << endl;
    }
}