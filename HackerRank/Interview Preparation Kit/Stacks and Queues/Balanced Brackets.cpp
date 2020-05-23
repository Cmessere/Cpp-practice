//Shiro23

//https://www.hackerrank.com/challenges/balanced-brackets/problem

#include <bits/stdc++.h>

using namespace std;

string isBalanced(string s) {
  stack<char> bracketsStack;
  string res;

  for (char &targetChar : s) {

    switch (targetChar) {
    case '(':
      bracketsStack.push(')');
      break;

    case '{':
      bracketsStack.push('}');
      break;

    case '[':
      bracketsStack.push(']');
      break;

    default:
      if (bracketsStack.empty() || bracketsStack.top() != targetChar)
        return res = "NO";
      else
        bracketsStack.pop();
    }
  }

  bracketsStack.empty() ? res = "YES" : res = "NO";
  return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
