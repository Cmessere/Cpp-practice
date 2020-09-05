//Shiro23

//https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/roy-and-profile-picture/


#include <iostream>

using namespace std;
void picture(int l){
    int h,w;
    
    cin >> w >> h;
    
    if(w < l || h < l)
        cout << "UPLOAD ANOTHER" << endl;
    else
        if(w == h)
            cout << "ACCEPTED" << endl;
        else
            cout << "CROP IT" << endl;
}
int main(){
    int l,n;
    
    cin >> l >> n;
    
    while(n > 0){
        picture(l);
        n--;
    }
}