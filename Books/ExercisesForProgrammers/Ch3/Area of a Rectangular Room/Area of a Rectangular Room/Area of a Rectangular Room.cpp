#include <iostream>

using namespace std;

double getInput(const string& dimension) {
    double size;

    cout << "What is the "<< dimension <<" of the room in feet?" << endl;
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
    const double SQUARED_FEET_TO_METERS = 0.09290304; 

    length = getInput("length");
    width = getInput("width");

    cout << "You entered dimensions of " << length << " feet by " << width << " feet." << endl;

    cout << "The Area is:" << endl;
    cout << length * width << " square feet" << endl;
    cout << (length * width)*SQUARED_FEET_TO_METERS << " square feet" << endl;
}