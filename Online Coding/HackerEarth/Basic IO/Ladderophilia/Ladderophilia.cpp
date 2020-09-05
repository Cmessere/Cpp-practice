//Shiro23

//https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/ladderophilia/

#include <iostream>

using namespace std;

int main(){
    string s1 = "*   *", s2 = "*****";
    int N; 
    
    cin >> N;
    
    while(N > 0){
        for( int i = 0; i < 3; i++){
            if(i == 2)
                cout << s2 << endl;
            else 
                cout << s1 << endl;
        }
        N--;
    }
    cout << s1 << endl;
    cout << s1 << endl;
}