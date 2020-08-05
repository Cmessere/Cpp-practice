#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
using std::chrono::system_clock;
using namespace std;

int main()
{
    string currentAge, retirementAge;

    system_clock::time_point now = system_clock::now();
    time_t tt = system_clock::to_time_t(now);
    struct tm timeinfo;
    localtime_s(&timeinfo, &tt);

    int currentYear = timeinfo.tm_year + 1900;

    cout << "What is your age?" <<endl;
    cin >> currentAge;
    cout << "At what age would you like to retire?" << endl;
    cin >> retirementAge;

    int remainingYears = stoi(retirementAge) - stoi(currentAge)

    cout << "You have " << remainingYears << " Years before you can retire." << endl;
    cout << "It's " << currentYear << ". so you can retire in " << currentYear + remainingYears << " before retiring" << endl;
}