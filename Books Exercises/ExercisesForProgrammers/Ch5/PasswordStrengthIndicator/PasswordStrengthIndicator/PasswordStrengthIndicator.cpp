#include <iostream>
constexpr auto MIN_SAFE_LENGTH = 8;

using namespace std;

void passwordValidator(const string &password, string &strength);

void passwordValidator(const string& password, string& strength) {
    bool isShort = false, isNumber = false, isChar =false, isSymbol = false;
    
    if (password.size() < MIN_SAFE_LENGTH)
        isShort = true;

    for (int i = 0; i < password.size(); i++) {
        if (isdigit(password[i]))
            isNumber = true;
        else if (isalnum(password[i]))
            isChar = true;
        else {
            isSymbol = true;
        }
    }

    if (!isShort && isNumber && isChar && isSymbol) {
        strength = "very strong";
    }
    else if (!isShort && isNumber && isChar) {
        strength = "strong";
    }
    else if (isShort && isNumber && isChar) {
        strength = "weak";
    }
    else if (isShort && isNumber) {
        strength = "very weak";
    }

}


int main()
{
    string password, strength;
    cout << "Insert the password to analyze: ";
    cin >> password;

    passwordValidator(password, strength);

    cout << "The password '" << password << "' is a " << strength << " password";
}