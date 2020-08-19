#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

struct employee {
    string name;
    string surname;
    string position;
    string date;
};

void initializeEmployees(vector<employee>& list);
void filterEmployees(const vector<employee>& list, const string filter, vector<employee>& filtered, const string choice);
void printEmployees(const vector<employee>& list);

void askForFieldToSort(std::string& choice);
void askForStringToSearch(std::string& choice);

void filterOnName(const employee& e, const std::string& filter, std::vector<employee>& filtered);
void filterOnPosition(const employee& e, const std::string& filter, std::vector<employee>& filtered);


using namespace std;

int main()
{
    vector<employee> employeesList, filtered;
    string choice, filter;

    askForFieldToSort(choice);
    askForStringToSearch(filter);
    initializeEmployees(employeesList);
    filterEmployees(employeesList, filter, filtered, choice);
    printEmployees(filtered);
}

void askForFieldToSort(std::string& choice)
{
    cout << "Do you want to sort on name or position? ";
    cin >> choice;

    std::for_each(choice.begin(), choice.end(), [](char& c) {c = ::toupper(c); });


    while (choice != "NAME" && choice != "POSITION") {
        cout << "Sorry, not a valid option. Please try again" << endl;
        cin >> choice;
    }
}

void askForStringToSearch(std::string& filter)
{
    cout << "Enter the string to search: ";
    cin >> filter;
    std::for_each(filter.begin(), filter.end(), [](char& c) {c = ::toupper(c); });
}

void printEmployees(const vector<employee>& list) {
    cout << setw(20) << "Name" << setw(20) << " Position" << setw(20) << " Separation Date" << endl;

    for (auto e : list) {
        cout << setw(20) << e.name + " " + e.surname << setw(20) << e.position << setw(20) << e.date << endl;
    }
}


void filterEmployees(const vector<employee>& list, const string filter, vector<employee>& filtered, const string choice) {

    for (auto e : list) {
        if (choice == "NAME") {
            filterOnName(e, filter, filtered);
        }
        else {
            filterOnPosition(e, filter, filtered);
        }
        
    }

}

void filterOnName(const employee& e, const std::string& filter, std::vector<employee>& filtered)
{
    string caseInsensitiveName, caseInsensitiveSurname;
    caseInsensitiveSurname = e.surname;
    caseInsensitiveName = e.name;

    std::for_each(caseInsensitiveName.begin(), caseInsensitiveName.end(), [](char& c) {c = ::toupper(c); });
    std::for_each(caseInsensitiveSurname.begin(), caseInsensitiveSurname.end(), [](char& c) {c = ::toupper(c); });

    if (caseInsensitiveSurname.find(filter) != string::npos || caseInsensitiveName.find(filter) != string::npos)
        filtered.push_back(e);
}

void filterOnPosition(const employee& e, const std::string& filter, std::vector<employee>& filtered)
{
    string caseInsensitivePosition;
    caseInsensitivePosition = e.position;

    std::for_each(caseInsensitivePosition.begin(), caseInsensitivePosition.end(), [](char& c) {c = ::toupper(c); });

    if (caseInsensitivePosition.find(filter) != string::npos)
        filtered.push_back(e);
}

void initializeEmployees(vector<employee>& list) {
    employee first, second, third, fourth, fifth, sixth;

    first.name = "John";
    first.surname = "Johnson";
    first.position = "Manager";
    first.date = "2016-12-31";

    second.name = "Tou";
    second.surname = "Xiong";
    second.position = "Software Engineer";
    second.date = "2016-10-05";

    third.name = "Michaela";
    third.surname = "Michaelson";
    third.position = "District Manager";
    third.date = "2015-12-19";

    fourth.name = "Jake";
    fourth.surname = "Jacobson";
    fourth.position = "Programmer";
    fourth.date = "";

    fifth.name = "Jacquelyn";
    fifth.surname = "Jackson";
    fifth.position = "DBA";
    fifth.date = "";

    sixth.name = "Sally";
    sixth.surname = "Weber";
    sixth.position = "Web Developer";
    sixth.date = "2015-12-18";

    list.insert(list.end(), { first, second, third, fourth, fifth, sixth });
}
