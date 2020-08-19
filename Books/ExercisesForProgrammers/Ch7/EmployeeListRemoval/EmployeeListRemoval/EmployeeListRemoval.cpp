#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include "EmployeeListRemoval.h"

using namespace std;

int main()
{
    list<string> employees;
    string targetToRemove, employeeFromFile;

    ifstream employeeFile;
    ofstream outputEmployeeFile;

    openFileAsInput(employeeFile);

    while (getline(employeeFile, employeeFromFile)) {
        employees.push_back(employeeFromFile);
    }

    while (1) {
        cout << "There are " << employees.size() << " employees" << endl;
        for (auto i : employees) {
            cout << i << endl;
        }
        cout << endl;

        cout << "Enter an employee name to remove, or 'stop' : ";
        getline(cin,targetToRemove);

        if (targetToRemove == "stop")
            break;

        auto it = find(employees.begin(), employees.end(), targetToRemove);

        if (it == employees.end()) {
            cout << "The inserted employee does not exist!";
        }
        else {
            employees.remove(targetToRemove);
        }
    }
    employeeFile.close();

    outputListToFile(outputEmployeeFile, employees);
}

void outputListToFile(std::ofstream& outputEmployeeFile, std::list<std::string>& employees)
{
    outputEmployeeFile.open("employees.txt");
    if (!outputEmployeeFile) {
        cout << "Unable to open file";
        exit(1);
    }

    for (auto i : employees) {
        outputEmployeeFile << i << endl;
    }
    outputEmployeeFile.close();
}

void openFileAsInput(std::ifstream& employeeFile)
{
    employeeFile.open("employees.txt");
    if (!employeeFile) {
        cout << "Unable to open file";
        exit(1);
    }
}
