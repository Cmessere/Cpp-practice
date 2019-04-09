//Shiro23

//https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/duration/


#include <iostream>

using namespace std;

int main(){
    int n, sh, sm, eh, em;
    
    cin >> n;
    
    while(n > 0){
        int rh = 0, rm = 0;
        cin >> sh >> sm >> eh >> em;
        
        rh = eh - sh;
        if( em - sm < 0)
            rh--;
            
        rm = ((60 -sm) + em)%60;  
        
        cout << rh << " " << rm << endl; 
        
        n--;
    }
}