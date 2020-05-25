//Shiro23

//https://www.hackerrank.com/challenges/c-tutorial-for-loop/problem


#include <bits/stdc++.h>

using namespace std;

int main()
{
  int x, y;
  const string num[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> x >> y;

  for (; x <= y; x++)
  {
    if (x <= 9)
    {
      switch (x)
      {
      case 0:
        cout << num[x] << "\n";
        break;

      case 1:
        cout << num[x] << "\n";
        break;

      case 2:
        cout << num[x] << "\n";
        break;

      case 3:
        cout << num[x] << "\n";
        break;

      case 4:
        cout << num[x] << "\n";
        break;

      case 5:
        cout << num[x] << "\n";
        break;

      case 6:
        cout << num[x] << "\n";
        break;

      case 7:
        cout << num[x] << "\n";
        break;

      case 8:
        cout << num[x] << "\n";
        break;

      case 9:
        cout << num[x] << "\n";
        break;
      }
    }
    else
    {
      if (x % 2 == 0)
        cout << "even"
             << "\n";
      else
        cout << "odd"
             << "\n";
    }
  }
  return 0;
}
