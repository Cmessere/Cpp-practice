#include <iostream>
#include <string>

using namespace std;

int main()
{
    string firstNumber, secondNumber;

    std::cout << "Insert the first number: " << endl;
    cin >> firstNumber;
    std::cout << "Insert the second number: " << endl;
    cin >> secondNumber;

    cout << firstNumber << " + " << secondNumber << " = " << stoi(firstNumber) + stoi(secondNumber) << endl;
    cout << firstNumber << " - " << secondNumber << " = " << stoi(firstNumber) - stoi(secondNumber) << endl;
    cout << firstNumber << " * " << secondNumber << " = " << stoi(firstNumber) * stoi(secondNumber) << endl;
    cout << firstNumber << " / " << secondNumber << " = " << stoi(firstNumber) / stoi(secondNumber) << endl;

}