//Shiro23

//https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/is-zoo-f6f309e7/description/

#include <bits/stdc++.h>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string inputString;
    short zCount=0, oCount=0;

    cin >> inputString;

    for(std::string::iterator it = inputString.begin(); it != inputString.end(); ++it) {
        *it == 'z' ? zCount++ : oCount++;
    }

    (zCount * 2) == oCount ? cout << "Yes" : cout << "No";

    return 0;
}
}