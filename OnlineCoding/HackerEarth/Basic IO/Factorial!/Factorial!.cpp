//Shiro23

//https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/find-factorial/


#include <iostream>

using namespace std;

void factorial(int N){
    int sum = 1;
    for(int i = N; i > 1; i--){
        sum *= i;
    }
    cout << sum;
}

int main(){
    int N;
    
    cin >> N;
    
    factorial(N);
}