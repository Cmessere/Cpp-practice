#include <iostream>
#include <map>
#include <vector>

using namespace std;

void initializeDrivingAges(map<string, short> &drivingAgeByCountry);
void getAge(short& age);
void createListOfAllowedCountries(std::map<std::string, short>& drivingAgeByCountry, short age, std::vector<std::string>& allowedCountries);
void printListOfAllowedCountries(std::vector<std::string>& allowedCountries);

int main()
{
    short age;
    map<string, short> drivingAgeByCountry;
    vector<string> allowedCountries;

    initializeDrivingAges(drivingAgeByCountry);

    getAge(age);

    createListOfAllowedCountries(drivingAgeByCountry, age, allowedCountries);

    if (allowedCountries.size() == 0) {
        cout << "You are not old enough to legally drive in any country.";
    }
    else {
        printListOfAllowedCountries(allowedCountries);
    }
}

void printListOfAllowedCountries(std::vector<std::string>& allowedCountries)
{
    cout << "You are old enough to legally drive in the following countries: \n";
    for (auto it : allowedCountries)
        cout << it << endl;
}

void createListOfAllowedCountries(std::map<std::string, short>& drivingAgeByCountry, short age, std::vector<std::string>& allowedCountries)
{
    for (std::map<std::string, short>::iterator it = drivingAgeByCountry.begin(); it != drivingAgeByCountry.end(); ++it) {
        if (age >= it->second) {
            allowedCountries.push_back(it->first);
        }
    }
}

void getAge(short& age)
{
    cout << "What is your age? ";
    cin >> age;

    while (cin.fail() || age < 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Only positive numbers allowed. Please try again" << endl;
        cin >> age;
    }
}

void initializeDrivingAges(map<string, short> &drivingAgeByCountry) {
    drivingAgeByCountry["USA"] = 16;
    drivingAgeByCountry["Mexico"] = 18;
    drivingAgeByCountry["USA"] = 18;
    drivingAgeByCountry["Austria"] = 18;
    drivingAgeByCountry["Belgium"] = 18;
    drivingAgeByCountry["Bulgaria"] = 18;
    drivingAgeByCountry["Croatia"] = 18;
    drivingAgeByCountry["Cyprus"] = 18;
    drivingAgeByCountry["Czech Republic"] = 18;
    drivingAgeByCountry["Denmark"] = 17;
    drivingAgeByCountry["Estonia"] = 18;
    drivingAgeByCountry["Finland"] = 18;
    drivingAgeByCountry["France"] = 18;
    drivingAgeByCountry["Germany"] = 18;
    drivingAgeByCountry["Greece"] = 18;
    drivingAgeByCountry["Iceland"] = 17;
    drivingAgeByCountry["Ireland"] = 17;
    drivingAgeByCountry["Italy"] = 18;
    drivingAgeByCountry["Latvia"] = 16;
    drivingAgeByCountry["Malta"] = 18;
    drivingAgeByCountry["Netherlands"] = 18;
    drivingAgeByCountry["Norway"] = 18;
    drivingAgeByCountry["Poland"] = 18;
    drivingAgeByCountry["Portugal"] = 18;
    drivingAgeByCountry["Romania"] = 18;
    drivingAgeByCountry["Spain"] = 18;
    drivingAgeByCountry["Sweden"] = 18;
    drivingAgeByCountry["Switzerland"] = 18;
    drivingAgeByCountry["United Kingdom"] = 17;
}