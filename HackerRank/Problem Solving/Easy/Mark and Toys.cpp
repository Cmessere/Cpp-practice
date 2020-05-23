//Shiro23

//https://www.hackerrank.com/challenges/two-strings/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {
int i = s2.length(), count = 0;
string temp = s2;
  for (auto c : s1) {
    if (s2.find(c) != string::npos) {
      count++;
      break;}
    }
    (count > 0) ? temp = "YES" : temp = "NO" ;
    return temp;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}