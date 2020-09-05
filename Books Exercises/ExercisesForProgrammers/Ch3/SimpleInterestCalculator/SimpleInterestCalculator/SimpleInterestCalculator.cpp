#include <iostream>

using namespace std;

double getDouble(const string& question) {
    double input;

    cout << "Enter the " << question << ": ";
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

    cout << "Enter the " << question << ": ";
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
	double rate, startingCapital, partialAmount;
	unsigned short investmentYears;

    startingCapital = getDouble("principal");
    rate = getDouble("rate of interest");
    investmentYears = getUnsignedShort("number of years");

    partialAmount = startingCapital;

    cout.precision(2);
    cout << fixed;

    for (unsigned short i = 0; i < investmentYears; i++)
    {
        partialAmount *= 1 + rate / 100;
        cout << "At the end of year " << i + 1 << " the investment will be worth $" << partialAmount <<endl;
    }
}