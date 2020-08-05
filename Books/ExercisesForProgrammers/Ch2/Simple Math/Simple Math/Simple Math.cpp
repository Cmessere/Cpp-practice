#include <iostream>
#include <string>
#include <regex>
#include <map>
using namespace std;

enum operations {
    sum,
    subtract,
    multiply,
    divide
};

string getInput(const string& inputNumber) {
    string input;
    regex onlyNumbers("^-?\\d*(\\.\\d+)?$");
    do
    {
        cout << "Insert the " << inputNumber << " number: " << endl;
        cin >> input;
        
        if (input.find('-') != string::npos)
            cout << "Only positive numbers allowed." << endl;

    } while (!regex_match(input, onlyNumbers));

    return input;
}

void printSum(const string &first, const string &second) {
    cout << stof(first) + stof(second) << endl;
}

void printSubtraction(const string& first, const string& second) {
    cout << stof(first) - stof(second) << endl;
}

void printProduct(const string& first, const string& second) {
    cout << stof(first) * stof(second) << endl;
}

void printDivide(const string& first, const string& second) {
    cout << stof(first) / stof(second) << endl;
}

void printOutput(const operations operation, const char & symbol,  const string& firstNumber, const string& secondNumber) {
    cout << firstNumber << " " << symbol << " " << secondNumber << " = ";

    switch (operation) {
    case 0:
        printSum(firstNumber, secondNumber);
        break;

    case 1:
        printSubtraction(firstNumber, secondNumber);
        break;

    case 2:
        printProduct(firstNumber, secondNumber);
        break;

    case 3:
        printDivide(firstNumber, secondNumber);
        break;

    default:
        break;
    }
}

int main()
{
    string firstNumber, secondNumber;

    firstNumber = getInput("first");
    secondNumber = getInput("second");

    printOutput(sum, '+', firstNumber, secondNumber);
    printOutput(subtract, '-', firstNumber, secondNumber);
    printOutput(multiply, '*', firstNumber, secondNumber);
    printOutput(divide, '/', firstNumber, secondNumber);
}