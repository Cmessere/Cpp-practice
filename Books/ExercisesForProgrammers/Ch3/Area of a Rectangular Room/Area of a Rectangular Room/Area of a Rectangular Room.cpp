#include <iostream>
#include <string>
using namespace std;

double getInput(const string& dimension, const string& measure) {
    double size;

    cout << "What is the "<< dimension <<" of the room in " << measure << "?" << endl;
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

double areaInMeters(const double& width, const double& length) {
    cout << length * width << " square meters" << endl;
    return length * width;
}

double areaInFeet(const double& width, const double& length) {
    cout << length * width << " square feet" << endl;
    return length * width;
}

int main()
{
    string measure;
    double length, width, area;
    const double SQUARED_FEET_TO_METERS = 0.09290304, SQUARED_METERS_TO_FEET = 10.764;

    cout << "Do you prefer meters or feet?" << endl;
    getline(std::cin, measure);
   
    while ((measure != "feet" && measure != "meters"))
    {
        cout << "That is not a valid option. Please try again: ";
        getline(std::cin, measure);
    }

    length = getInput("length", measure);
    width = getInput("width", measure);

    cout << "You entered dimensions of " << length << " " << measure <<" by " << width << " "  << measure << endl;

    cout << "The Area is:" << endl;
    if (measure == "meters") {
        area = areaInMeters(width, length);
        cout << (length * width)*SQUARED_METERS_TO_FEET << " square feet" << endl;
    }
    else {
        area = areaInFeet(width, length);
        cout << (length * width) * SQUARED_FEET_TO_METERS << " square meters" << endl;
    }
}