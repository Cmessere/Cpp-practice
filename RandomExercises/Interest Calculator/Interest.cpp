#include "interest.h"
#include <iostream>

using namespace std;

void depositOnly(double &balance, short &months, double &monthlyDeposit, float &interestRate){
    getValuesFromUser(balance, months, monthlyDeposit, interestRate=-1, 0);
    
    double investedSum = balance;

    for(short i = 0; i < months; i++){
        balance += monthlyDeposit;
        cout << "Month: " << i << " Balance: " << balance << endl;
        investedSum += monthlyDeposit;
    }

    cout << "Net gain: " << balance - investedSum;
}
void fixedRateInterest(double &balance, short &months, double &monthlyDeposit, float &interestRate){
    getValuesFromUser(balance, months, monthlyDeposit, interestRate, 0);
    
    double investedSum = balance;

    for(short i = 0; i < months; i++){
        balance = balance + monthlyDeposit + balance*interestRate;
        cout << "Month: " << i << " Balance: " << balance << endl;
        investedSum += monthlyDeposit;
    }

    cout << "Net gain: " << balance - investedSum;
}

void variableRateInterest(double &balance, short &months, double &monthlyDeposit, float &interestRate, float &upperInterestRate){
    getValuesFromUser(balance, months, monthlyDeposit, interestRate = -2, upperInterestRate);
    
    float randomInterestRate = (upperInterestRate*100 + interestRate*100)/((upperInterestRate*100 - interestRate*100));
    double investedSum = balance;

    for(short i = 0; i < months; i++){
        balance = balance + monthlyDeposit + balance*(randomInterestRate/100);
        cout << "Month: " << i << " Balance: " << balance << endl;
        investedSum += monthlyDeposit;

    }

    cout << "Net gain: " << balance - investedSum;
}

int main()
{
    short months, interestOption;
    float interestRate, upperInterestRate;
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
            variableRateInterest(balance, months, monthlyDeposit, interestRate, upperInterestRate);
            break;

        default:    
            break;
    }
}

