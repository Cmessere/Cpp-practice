//Shiro23

//https://www.hackerrank.com/challenges/alternating-characters/problem

#include <bits/stdc++.h>

using namespace std;
#define MIL 1000000000
// Complete the maxMin function below.
int maxMin(int k, vector<int> arr) {
  int min = MIL, max = 0, unfairness = MIL;

  sort(arr.begin(), arr.end());

for(int j = 1; j < arr.size()-1; j++){
  for (int i = j; i < k; i++) {
      if(arr[i] < min)
        min = arr[i];
      if(arr[i]> max)
        max = arr[i];
  }
}

for (auto i = 0; i < arr.size() - k + 1; i++) {
      min = arr[i];
      max = arr[i + k - 1];
      if ((max - min) < unfairness)
        unfairness = max - min;
}

    return unfairness;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    int result = maxMin(k, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
