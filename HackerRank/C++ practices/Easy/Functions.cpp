//Shiro23

//https://www.hackerrank.com/challenges/c-tutorial-functions/submissions/code/99213526

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int max_of_four(int a, int b, int c, int d){
    int max = a;
    vector<int> vec = {a,b,c,d};
    for(int x = 0; x < vec.size(); x++){
        if(vec[x]>max)
            max = vec[x];
    }

    return max;
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;