//Shiro23

//https://www.hackerrank.com/challenges/ctci-making-anagrams/problem

#include <bits/stdc++.h>

using namespace std;

int makeAnagram(string a, string b) {
    short count = 0;
    vector<int> vec(26, 0);

    for(auto i : a){++vec[i - 'a'];}
    for(auto i : b){--vec[i - 'a'];}

    for(auto val:vec){count+= abs(val);}

    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}

