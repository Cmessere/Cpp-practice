//Shiro23

//https://www.hackerrank.com/challenges/c-tutorial-stringstream/problem

#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
    vector<int> integerVector;
	stringstream ss(str);

    char comma;
    int integerToAdd;

    while(ss){
        ss>> integerToAdd >> comma;

        integerVector.push_back(integerToAdd);
    } 
    
    return integerVector;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);

    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}