#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

void printList(const int& size);
void printTable(const int& size);

void printList(const int& size) {
    for (int i = 0; i <= size; i++) {
        for (int j = 0; j <= size; j++) {
            cout << i << " X " << j << " = " << i * j << endl;
        }
        cout << endl;
    }
}

void printTable(const int &size) {
    cout << setw(5) << right << " ";

    for (int i = 0; i <= size; i++) {
        cout << setw(5) << right << i;
    }

    cout << endl;

    for (int i = 0; i <= size; i++) {
        cout << setw(5) << right << i;

        for (int j = 0; j <= size; j++) {
            cout << setw(5) << right << j * i;
        }
        cout << endl;
    }
}


int main()
{
    string choice;
    int size;

    cout << "Do you want to visualize the result as a 'list' or as a 'table'? ";
    cin >> choice;

    std::for_each(choice.begin(), choice.end(), [](char& c) {c = ::toupper(c); });

    cout << "Enter the table size: ";
    cin >> size;

    while (choice != "LIST" && choice != "TABLE") {
        cout << "Sorry, wrong option. Please try again." << endl;
        cin >> choice;

        std::for_each(choice.begin(), choice.end(), [](char& c) {c = ::toupper(c); });
    }

    if (choice == "LIST") {
        printList(size);
    }
    else {
        printTable(size);
    }
}