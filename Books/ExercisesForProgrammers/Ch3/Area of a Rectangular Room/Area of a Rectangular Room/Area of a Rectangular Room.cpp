#include <iostream>

using namespace std;

int main()
{
    double length, width;
    const double SQUARED_FEET_TO_METERS = 0.09290304; 

    cout << "What is the length of the room in feet?" << endl;
    cin >> length;
    cout << "What is the width of the room in feet?" << endl;
    cin >> width;

    cout << "You entered dimensions of " << length << " feet by " << width << " feet." << endl;

    cout << "The Area is:" << endl;
    cout << length * width << " square feet" << endl;
    cout << (length * width)*SQUARED_FEET_TO_METERS << " square feet" << endl;
}