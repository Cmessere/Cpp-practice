//Shiro23

//https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/tds-and-his-breakup/

#include <iostream>

using namespace std;

int main(){
    int friends, threshold, skillValue;
    
    cin >> friends;
    cin >> threshold;
    
    while(friends > 0){
        cin >> skillValue;
        
        if(skillValue >= threshold)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        
        friends--;
    }
}