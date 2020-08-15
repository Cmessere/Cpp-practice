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

void outputResult( const unsigned short &cans ) {
    cout << "You're going to need " << cans << " to completely paint the room." << endl;
}

void squareRoom() {
    double length, width;
    unsigned short paintCans = 1;

    length = getInput("length");
    width = getInput("width");

    paintCans = ceil(length * width / FEET_SQUARED_PER_GALLON);

    outputResult(paintCans);
}

void circularRoom(){
    double radius;
    unsigned short paintCans = 1;

    radius = getInput("radius");

    paintCans = ceil((PI * radius * radius) / FEET_SQUARED_PER_GALLON);

    outputResult(paintCans);
}

void lShapedRoom() {
    double majorLength, majorWidth, minorLength, minorWidth;
    unsigned short paintCans = 1;

    majorLength = getInput("length of the long side");
    majorWidth = getInput("width of the long side");
    minorLength = getInput("length of the small side");
    minorWidth = getInput("width of the small side");

    paintCans = ceil((majorLength * majorWidth + minorLength * minorWidth) / FEET_SQUARED_PER_GALLON);

    outputResult(paintCans);
}

int main()
{
    string shape;
    cout << "Is the room squared, circular or L shaped?" << endl;
    
    getline(std::cin, shape);

    while ((shape != "squared" && shape != "circular" && shape != "L"))
    {
        cout << "That is not a valid option. Please try again: ";
        getline(std::cin, shape);
    }

    if (shape == "squared")
        squareRoom();
    else if (shape == "circular")
        circularRoom();
    else
        lShapedRoom();
}