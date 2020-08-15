#include <iostream>
#include <math.h>

using namespace std;
constexpr auto FEET_SQUARED_PER_GALLON = 350;

double getInput(const string& dimension) {
    double size;

    cout << "What is the " << dimension << " of the room?" << endl;
    cin >> size;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Only numbers allowed. Please try again" << endl;
        cin >> size;
    }
    return size;
}

int main()
{
	double length, width;
	unsigned short paintCans = 1;

    length = getInput("length");
    width = getInput("width");

	paintCans = ceil(length * width / FEET_SQUARED_PER_GALLON);

	cout << "You're going to need " << paintCans << " to completely paint the room." << endl;
}