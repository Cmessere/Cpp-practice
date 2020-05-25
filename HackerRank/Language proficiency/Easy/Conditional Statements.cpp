//Shiro23

//https://www.hackerrank.com/challenges/c-tutorial-conditional-if-else/copy-from/101352797

#include <bits/stdc++.h>

using namespace std;



int main()
{
  const string kOnesPlaces[] = {"zero","one", "two","three","four", "five","six", "seven", "eight", "nine"};

  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  // Write Your Code Here
    if(n < 10)
    {
        switch(n){
            case 0:
            cout << kOnesPlaces[n];
            break;
            
            case 1:
            cout << kOnesPlaces[n];
            break;

            case 2:
            cout << kOnesPlaces[n];
            break;

            case 3:
            cout << kOnesPlaces[n];
            break;

            case 4:
            cout << kOnesPlaces[n];
            break;

            case 5:
            cout << kOnesPlaces[n];
            break;

            case 6:
            cout << kOnesPlaces[n];
            break;

            case 7:
            cout << kOnesPlaces[n];
            break;

            case 8:
            cout << kOnesPlaces[n];
            break;

            case 9:
            cout << kOnesPlaces[n];
            break;
        }
    }
    else{
        cout << "Greater than 9";
    }
  return 0;
}
