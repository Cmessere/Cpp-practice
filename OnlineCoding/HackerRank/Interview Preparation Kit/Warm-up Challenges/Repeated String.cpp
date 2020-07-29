//Shiro23

//https://www.hackerrank.com/challenges/repeated-string/problem

#include <bits/stdc++.h>


using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    long size = n / s.length(), mod = n % size;
    long count = 0;

    if(n > s.length()){
        for(long i = 0; i < s.length(); i++){
        if(s[i] == 'a')
            count++;
        }
        count *= size;

        for(long i = 0; i < mod; i++){
        if (s[i] == 'a')
            count++;
        }
    }
    else{
        for(long i = 0; i < n; i++)
          if (s[i] == 'a')
            count++;
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
