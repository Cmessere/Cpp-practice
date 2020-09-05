//Shiro23

//https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/seating-arrangement-1/



#include <iostream>

using namespace std;

int main(){
    int num;
    bool prime = true;
    
    cin >> num;

    
    int flag = 2;
    
    for(int i = 2; i < num; i++){
        prime = true;
        for(int j = 2; j < i; j++){
            if(i % j == 0){
                prime = false;
                break;}
        }
        
        if(prime)
            cout << i << " ";
    }
    
}