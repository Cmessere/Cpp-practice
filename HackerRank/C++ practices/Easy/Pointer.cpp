//Shiro23

//https://www.hackerrank.com/challenges/c-tutorial-pointer/copy-from/99213841

#include <bits/stdc++.h>
#include <math.h>

using namespace std;

void update(int *a,int *b) { 
    int x, y;
    x  = *a + *b;
    y = abs(*a - *b);
    *a = x;
    *b = y;

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int a, b;
    int *pa = &a, *pb = &b;
    
    cin >> a >> b;
    update(pa, pb);
    cout << a << "\n"<< b << "\n";

    return 0;
}