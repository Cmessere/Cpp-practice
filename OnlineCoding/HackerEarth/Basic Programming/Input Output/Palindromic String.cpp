//Shiro23

//https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/palindrome-check-2/description/

#include <bits/stdc++.h>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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
    
    palindrome  ? cout << "YES" : cout << "NO";
}