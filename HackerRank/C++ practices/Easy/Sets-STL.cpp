//Shiro23

//https://www.hackerrank.com/challenges/cpp-sets/copy-from/151471461

#include <bits/stdc++.h>
#include <set>
#include <algorithm>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int queriesNumber;
    short typeOfQuery;
    long targetValue;
    set<int> integerSet;

    cin >> queriesNumber;

    for(int i = 0; i < queriesNumber; i++){
        cin >> typeOfQuery >> targetValue;

        switch (typeOfQuery) {
            case 1:
            integerSet.insert(targetValue);
            break;

            case 2:
            integerSet.erase(targetValue);
            break;

            case 3:
            integerSet.find(targetValue) != integerSet.end() ?                      cout << "Yes" << endl : cout << "No" << "\n";
        }

    }

    return 0;
}

