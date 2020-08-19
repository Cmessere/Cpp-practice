#include <iostream>
#include <list>
#include <string>

using namespace std;

int main()
{
    list<string> employees = { "John Smith", "Jackie Jackson","Chris Jones","Amanda Cullen","Jeremy Goodwin" };
    string targetToRemove;

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
}