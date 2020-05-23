//Shiro23

//https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/palindrome-check-2/


using namespace std;
#include <iostream>

int main(){
    string str;
    bool palindrome = true;
    cin >> str;
    
    int i = 0, j = str.length()-1;

    while(i < j){
        if(str[i] != str[j]){
            palindrome = false;
        }
        i++;
        j--;
    }
    
    if(palindrome)
        cout << "YES";
    else
        cout << "NO";
}