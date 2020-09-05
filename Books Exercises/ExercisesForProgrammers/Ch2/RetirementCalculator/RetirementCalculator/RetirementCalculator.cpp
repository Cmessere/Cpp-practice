#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
using std::chrono::system_clock;
using namespace std;

void printRetirement(const int& remaining, const int& current) {

    if (remaining < 0) {
        cout << "Oh! you can already retire!" << endl;
    }
    else {
        cout << "You have " << remaining << " Years before you can retire." << endl;
        cout << "It's " << current << ". so you can retire in " << current + remaining << " before retiring" << endl;
    }
}

int getCurrentYear() {
    system_clock::time_point now = system_clock::now();
    time_t tt = system_clock::to_time_t(now);

    struct tm timeinfo;
    localtime_s(&timeinfo, &tt);

    return timeinfo.tm_year + 1900;
}

int main()
{
    string currentAge, retirementAge;

    int currentYear = getCurrentYear();

    cout << "What is your age?" << endl;
    cin >> currentAge;
    cout << "At what age would you like to retire?" << endl;
    cin >> retirementAge;

    int remainingYears = stoi(retirementAge) - stoi(currentAge);

    printRetirement(remainingYears, currentYear);
}