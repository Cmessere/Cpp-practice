//Shiro23

//https://www.hackerrank.com/challenges/cpp-lower-bound/problem

#include <vector>
#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int vectorSize, queries;
    int valueToInsert, targetValue;

    cin >> vectorSize;

    vector<int> vec;

    for (int i = 0; i < vectorSize; i++) {
      cin >> valueToInsert;
      vec.push_back(valueToInsert);
    }

    cin >> queries;

    while(queries--){
      cin >> targetValue;

      std::vector<int>::iterator lowerBound;
      lowerBound = std::lower_bound(vec.begin(), vec.end(), targetValue); 

      cout << (*lowerBound == targetValue ? "Yes " : "No ")
           << (lowerBound - vec.begin()) + 1 << endl;
    }

    return 0;
}
