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
	double rate, startingCapital, calculatedAmount;
	unsigned short investmentYears;

    startingCapital = getDouble("principal");
    rate = getDouble("rate of interest");
    investmentYears = getUnsignedShort("number of years");

	calculatedAmount = startingCapital*(1 + rate / 100 * investmentYears);

	cout << "After " << investmentYears << " years at " << rate << "%, the investment will be worth $" << calculatedAmount;
}