//Shiro23

//https://www.hackerrank.com/challenges/counting-valleys/problem

#include <bits/stdc++.h>

using namespace std;

int countingValleys(int n, string s) {
    int count = 0, height = 0;

    for(int i = 0; i < n; i++){
        s[i] == 'U' ? height++ : height--;
        
        if(height == 0 && s[i] == 'U')
            count++;
    }
    
    return count;

}

int main()
{    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
