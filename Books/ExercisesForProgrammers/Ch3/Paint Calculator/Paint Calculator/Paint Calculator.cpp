#include <iostream>
#include <math.h>
#include <string>

using namespace std;
constexpr auto FEET_SQUARED_PER_GALLON = 350;
constexpr auto PI = 3.14259;

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

void squareRoom() {
    double length, width;
    unsigned short paintCans = 1;

    length = getInput("length");
    width = getInput("width");

    paintCans = ceil(length * width / FEET_SQUARED_PER_GALLON);

    cout << "You're going to need " << paintCans << " to completely paint the room." << endl;
}

void circularRoom() {
    double radius;
    unsigned short paintCans = 1;

    radius = getInput("radius");

    paintCans = ceil((PI * radius * radius) / FEET_SQUARED_PER_GALLON);

    cout << "You're going to need " << paintCans << " to completely paint the room." << endl;
}

int main()
{
    string shape;
    cout << "Is the room squared or circular?" << endl;
    
    getline(std::cin, shape);

    while ((shape != "squared" && shape != "circular"))
    {
        cout << "That is not a valid option. Please try again: ";
        getline(std::cin, shape);
    }

    if (shape == "squared")
        squareRoom();
    else
        circularRoom();

}