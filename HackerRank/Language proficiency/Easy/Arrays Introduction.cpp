//Shiro23

https://www.hackerrank.com/challenges/arrays-introduction/copy-from/99214564

#include <cmath>
#include <bits/stdc++.h>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size;
    cin >> size;
    int *arr = new int [size];

    for(int i = 0; i < size; i++){
      cin >> arr[i];
    }

    for (int i = size - 1; i >= 0; i--)
      cout << arr[i] << " ";
    delete[] arr;
    return 0;
}
