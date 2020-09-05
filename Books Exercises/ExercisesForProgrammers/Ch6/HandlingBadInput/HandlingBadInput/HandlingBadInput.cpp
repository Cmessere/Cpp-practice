#include <iostream>

using namespace std;

int main()
{
	double rate;

	while(1)
	{
		cout << "What is the rate of return? ";
		cin >> rate;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Only numbers allowed. Please try again" << endl;
		}
		else if (rate == 0)
			cout << "Hey, you cannot divide by 0, it can destroy the universe." << endl;		
		else {
			break;
		}
	}

	cout << "It will take " << 72/rate << " years to double your initial investment.";
}