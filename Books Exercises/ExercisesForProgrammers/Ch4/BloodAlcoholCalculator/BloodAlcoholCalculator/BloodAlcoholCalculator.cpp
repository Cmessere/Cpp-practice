#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

constexpr auto FEMALE_RATIO = 0.66;
constexpr auto MALE_RATIO = 0.73;
constexpr auto LEGAL_LIMIT = 0.08;

double getDouble(const string &question) {
    double input;

    cout << "What is " << question << "? ";
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

string getString(const string &question) {
    string input;

    cout << question;
    cin >> input;

    std::for_each(input.begin(), input.end(), [](char& c) {c = ::toupper(c); });

    while (input != "M" && input != "F")
    {
        cout << "Please enter either 'M' or 'F'" << endl;
        cin >> input;
    }
    return input;
}


int main()
{
    double weight, alcoholAmount, alcoholRate, BAC, ratio;
    short hours;
    string gender;

    weight = getDouble("your weight in pounds");
    gender = getString("What is your gender? ");

    cout << "What is your gender? ";
    cin >> gender;

    alcoholAmount = getDouble("the number of drinks consumed");
    alcoholRate = getDouble("the amount of alcohol consumed in ounces");
    hours = getDouble("the number of hours since last drink");

    gender == "m" ? ratio = MALE_RATIO : ratio = FEMALE_RATIO;

    BAC = (alcoholAmount * alcoholRate / weight * ratio) - (0.15 * hours);
    
    if (BAC < 0) {
        BAC = 0;
    }

    cout << "Your BAC is " << BAC << endl;
    BAC < LEGAL_LIMIT ? cout << "You can drive" : cout << "It is not legal for you to drive";
}