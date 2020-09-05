//Shiro23

//https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/find-product/description/

#include <bits/stdc++.h>
#define N 1000000007
using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long s, sum = 1, x;

    cin >> s;

    for (long long i = 0; i < s; i++)
    {
        cin >> x;
        sum = sum * x % N;
    }
    cout << sum;
}