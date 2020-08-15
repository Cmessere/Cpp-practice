#include <iostream>
#include <math.h>

using namespace std;
constexpr auto FEET_SQUARED_PER_GALLON = 350;


int main()
{
	double length, width;
	unsigned short paintCans = 1;

	cout << "What is the lenght of the room in feet?" << endl;
	cin >> length;
	cout << "What is the width of the room in feet?" << endl;
	cin >> width;

	paintCans = ceil(length * width / FEET_SQUARED_PER_GALLON);

	cout << "You're going to need " << paintCans << " to completely paint the room." << endl;
}