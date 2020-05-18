//Shiro23

//https://www.hackerrank.com/challenges/variable-sized-arrays/copy-from/99215443

#include <cmath>
#include <vector>

#include <bits/stdc++.h>

#include <algorithm>
using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

  int nvec, nque;
  cin >> nvec >> nque;

  vector<vector<int>> a(nvec);

    for (int i = 0; i < nvec; i++) {
        int size = 0;
        cin >> size;
        a[i].resize(size);
        for (int j = 0; j < size; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < nque; i++) {
        int idx, pos;
        cin >> idx >> pos;
        cout << a[idx][pos] << "\n";
    }
      return 0;
}

