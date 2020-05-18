//Shiro23

//https://www.hackerrank.com/challenges/vector-sort/copy-from/100049656

#include <vector>
#include <algorithm>

#include <bits/stdc++.h>
using namespace std;


int main() {
    int size;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> size;

    vector<int> vec(size);
    for(int i = 0; i < vec.size(); i++){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());

    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    return 0;
}
