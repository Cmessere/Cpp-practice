#include <iostream>
#include <math.h>
#include "CompoundInterestCalculator.h"

using namespace std;

double getDouble(const string& question) {
    double input;

    cout << "Enter the " << question << "? ";
    cin >> input;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Only numbers allowed. Please try again" << endl;
        cin >> input;
    }
    return input;
}

unsigned short getUnsignedShort(const string& question) {
    unsigned short input;

    cout << "Enter the " << question << "? ";
    cin >> input;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Only numbers allowed. Please try again" << endl;
        cin >> input;
    }
    return input;
}

int main()
{
    double rate, startingCapital, calculatedInterest;
    unsigned short investmentYears, compoundedRate;

    startingCapital = getDouble("principal");
    rate = getDouble("rate of interest");
    investmentYears = getUnsignedShort("number of years");
    compoundedRate = getUnsignedShort("number of times the interest is compounded per year");

    calculatedInterest = startingCapital*pow((1 + rate/100 / compoundedRate), compoundedRate* investmentYears);
    
    outputInterest(startingCapital, rate, compoundedRate, calculatedInterest, investmentYears);
}

void outputInterest(const double &startingCapital, const double& rate, const unsigned short& compoundedRate, const double& calculatedInterest, const unsigned short& investmentYears)
{
    cout.precision(2);
    cout << fixed;

    cout << "$" << startingCapital << " invested at " << rate << "% for " << investmentYears << " years compounded " << compoundedRate << " times per year is $"
        << calculatedInterest << ".";
}
