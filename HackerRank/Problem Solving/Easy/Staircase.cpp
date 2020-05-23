//Shiro23

//https://www.hackerrank.com/challenges/staircase/problem

#include <bits/stdc++.h>

using namespace std;

void staircase(const int n) {

    for(short i = 0; i < n; i++){
        for(short j = 1; j <= n; j++){
            j >= n-i ? cout << "#" : cout << " ";
        }
        cout << endl;
    }

}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    staircase(n);

    return 0;
}
