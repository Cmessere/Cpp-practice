//Shiro23

//https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/bricks-game-5140869d/


using namespace std;
#include <iostream>

int main(){
    int N, p = 1, m;
    string name;
    
    cin >> N;
    
    while(N > 0){
        N = N - p;
        m = p * 2;
        p++;
        if(N <= 0){
            name = "Patlu";
            break;
        }
        N = N - m;
        if(N <= 0){
            name = "Motu";
            break;
        }

    }
    cout << name;
}