//Shiro23

//https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/two-strings-4/


using namespace std;

#include <iostream>
#include <algorithm>

int main(){
    int N;
    string str1, str2;
    bool same = true;
    
    cin >> N;
    
    while(N > 0){
        same = true;
        cin >> str1 >> str2;
        
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        
        for(int i = 0; i < str1.length(); i++){
            if(str1[i] != str2[i]){
                same = false;
                break;
            }
        }
        
        if(same)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        
        N--;
    }
}