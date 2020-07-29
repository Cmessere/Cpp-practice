//Shiro23

//https://www.hackerrank.com/challenges/operator-overloading/copy-from/99217280

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Matrix{
    public:
    vector<vector<int>> a;
    Matrix operator+(Matrix &r){
        Matrix ret;
        ret.a = vector<vector<int>>(r.a.size());

        for(int i = 0; i < r.a.size(); i++){
        ret.a[i] = vector<int>(r.a[i].size());
        for(int j = 0; j < r.a[i].size(); j++)
            ret.a[i][j] = this->a[i][j] + r.a[i][j];
        }
        return ret;
    }
};

int main () {
   int cases,k;
   cin >> cases;
   for(k=0;k<cases;k++) {
      Matrix x;
      Matrix y;
      Matrix result;
      int n,m,i,j;
      cin >> n >> m;
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         x.a.push_back(b);
      }
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         y.a.push_back(b);
      }
      result = x+y;
      for(i=0;i<n;i++) {
         for(j=0;j<m;j++) {
            cout << result.a[i][j] << " ";
         }
         cout << endl;
      }
   }  
   return 0;
}



