//Shiro23

//https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/sum-it-if-you-can-4867f851/

#include <iostream>
#define N 10000000000
#define M 1000000000
using namespace std;

int main(){
    long x;
    int sum = 0, j = 10, y;
    
    cin >> x;
    
    if(x % M > N)
        cout << "Illegal ISBN";

    
    while(x > 0){
        y = x % 10;
        x = x / 10;
        
        sum += j * y;
        j--;
    }
    
    
    if(sum % 11 == 0)
        cout << "Legal ISBN";
    else
        cout << "Illegal ISBN";
    
}