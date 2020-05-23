//Shiro23

//https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/seating-arrangement-1/


#include <iostream>

using namespace std;

void seatFinder(){
    int seatNum, group, frontSeat;
    string type = "WS";
    cin >> seatNum;
    
    group = seatNum % 12;
    
    if(group % 6 == 0 || group % 6 == 1)
        type = "WS";
    else if(group % 6 == 5 || group % 6 == 2)
        type = "MS";
    else
        type = "AS";
        
    if(group > 6){
        switch(group){
            case 7:
            frontSeat = seatNum - 1;
            break;
            
            case 8:
            frontSeat = seatNum - 3;
            break;
            
            case 9:
            frontSeat = seatNum - 5;
            break;
            
            case 10:
            frontSeat = seatNum - 7;
            break;
            
            case 11:
            frontSeat = seatNum - 9;
            break;
        }
    }
    else{
        switch(group){
            case 6:
            frontSeat = seatNum + 1;
            break;
            
            case 5:
            frontSeat = seatNum + 3;
            break;
            
            case 4:
            frontSeat = seatNum + 5;
            break;
            
            case 3:
            frontSeat = seatNum + 7;
            break;
            
            case 2:
            frontSeat = seatNum + 9;
            break;
            
            case 1:
            frontSeat = seatNum + 11;
            break;
            
            case 0:
            frontSeat = seatNum - 11;
            break;
        }
    }
    
    
    cout << frontSeat << " " << type << endl;
}

int main(){
    int iterations;
    
    cin >> iterations;
    
    while (iterations > 0){
        seatFinder();
        iterations--;
    }
}