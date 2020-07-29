//Shiro23

//https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/modify-the-string/

using namespace std;

#include <iostream>

int main(){
    string str;
    
    cin >> str;
    
    for(int i = 0; i < str.length(); i++){
        if((str[i] >= 'A') && (str[i] <= 'Z')){
            str[i] =  tolower(str[i]);
        }
        else{
            str[i] =  toupper(str[i]);
        }
    }
    
    cout << str;
}