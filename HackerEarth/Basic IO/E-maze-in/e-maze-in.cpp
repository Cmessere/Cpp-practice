//Shiro23

//https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/e-maze-in-1aa4e2ac/


#include <iostream>

using namespace std;

int main(){
    string direction;
    int h = 0, w = 0;
    
    cin >> direction;
    
    for(int i = 0; i < direction.length(); i++){
        switch(direction[i]){
            
            case 'L':
            w--;
            break;
            
            case 'R':
            w++;
            break;
            
            case 'U':
            h++;
            break;
            
            case 'D':
            h--;
            break;
        }
    }
    
    cout << w << " " << h;
}