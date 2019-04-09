//Shiro23

//https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/seven-segment-display-nov-easy-e7f87ce0/
using namespace std;

#include <iostream>

using namespace std;

int main(){
    int iterations, y, num = 0;
    string x;
    cin >> iterations;
    
    while(iterations > 0){

        cin >> x;   
        //cout << x;
        for(int i = 0; i < x.length(); i++){

            switch(x[i]){
                case '0':
                num = num + 6;
                break;
            
                case '1':
                num = num + 2;
                break;
            
                case '2':
                num = num + 5;
                break;
            
                case '3':
                num = num + 5;
                break;
            
                case '4':
                num = num + 4;
                break;
            
                case '5':
                num = num + 5;
                break;
            
                case '6':
                num = num + 6;
                break;
            
                case '7':
                num = num + 3;
                break;
            
                case '8':
                num = num + 7;
                 break;
            
                case '9':
                num = num + 6;
                break;
                }
        }
        //cout << "sum = " << num <<endl;
        
        if(num % 2 == 0){
            for(int i = 1; i <= num/2 ; i++)
                cout << '1';
        }
        else{
            num-=3;
            cout << '7';
            for(int i = 1; i <= num/2 ; i++)
                cout << '1';
        }
        
        cout << endl;
        num = 0;
        
        iterations--;
    }
}