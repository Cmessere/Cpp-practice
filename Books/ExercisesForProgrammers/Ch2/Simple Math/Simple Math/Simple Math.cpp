#include <iostream>
#include <string>
#include <regex>
using namespace std;

string getInput(const string& inputNumber) {
    string input;
    regex onlyNumbers("[0-9]+.?[0-9]+");

    do
    {
        cout << "Insert the " << inputNumber << " number: " << endl;
        cin >> input;
        
        if (input.find('-') != string::npos)
            cout << "Only positive numbers allowed." << endl;

    } while (!regex_match(input, onlyNumbers));

    return input;
}

int main()
{
    string firstNumber, secondNumber;

    firstNumber = getInput("first");
    secondNumber = getInput("second");

    cout << firstNumber << " + " << secondNumber << " = " << stof(firstNumber) + stof(secondNumber) << endl;
    cout << firstNumber << " - " << secondNumber << " = " << stof(firstNumber) - stof(secondNumber) << endl;
    cout << firstNumber << " * " << secondNumber << " = " << stof(firstNumber) * stof(secondNumber) << endl;
    cout << firstNumber << " / " << secondNumber << " = " << stof(firstNumber) / stof(secondNumber) << endl;

}