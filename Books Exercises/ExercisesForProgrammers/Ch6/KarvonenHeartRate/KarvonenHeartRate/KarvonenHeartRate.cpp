#include <iostream>
#include <iomanip>

constexpr auto LOWER_RATE = 55;
constexpr auto UPPER_RATE = 95;

using namespace std;

void getInput(const string& question, int& input);
void printKanovanTable(const int& rate, const int& age);

int main()
{
    int pulse, age;

    getInput("What is your resting pulse? ", pulse);
    getInput("What is your age? ", age);

    printKanovanTable(pulse, age);
}

void getInput(const string& question, int& input) {
    cout << question;
    cin >> input;

    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Only numbers allowed. Please try again" << endl;
        cin >> input;
    }
}

void printKanovanTable(const int& rate, const int& age) {
    cout << setw(10) << right << "Resting pulse: " << rate << " age:" << age << endl << endl;

    cout << setw(15) << "Intensity" << setw(15) << "Rate\n";
    int target;

    for (double i = LOWER_RATE; i <= UPPER_RATE; i += 5) {
        target = (((220 - age) - rate) * i/100) + rate;
        cout << setw(14) << i << "%" << setw(10) << target << " bpm" << endl;
    }
}