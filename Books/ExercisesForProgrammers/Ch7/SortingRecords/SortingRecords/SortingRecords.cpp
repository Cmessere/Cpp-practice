#include <iostream>
#include <list>
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

void initializeEmployees(vector<employee> &list);
void sortEmployees(vector<employee> &list);
void printEmployees(const vector<employee> &list);

void initializeEmployees(vector<employee> &list) {
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

void sortEmployees(vector<employee> &list) {

    sort(list.begin(), list.end(), [](const employee& lhs, const employee& rhs)
        {
            if (lhs.surname != rhs.surname)
            {
                return lhs.surname < rhs.surname;
            }
            else
            {
                return lhs.surname < rhs.surname;
            }

        });

}

void printEmployees(const vector<employee> &list) {
    cout << setw(20) << "Name" << setw(20) << " Position" << setw(20) << " Separation Date" << endl;

    for (auto e : list) {
        cout << setw(20) << e.name + " " + e.surname << setw(20) << e.position << setw(20) << e.date << endl;
    }
}


int main()
{
    vector<employee> employeesList;

    initializeEmployees(employeesList);
    sortEmployees(employeesList);
    printEmployees(employeesList);
}