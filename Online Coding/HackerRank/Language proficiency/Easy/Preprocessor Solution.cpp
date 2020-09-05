//Shiro23

//https://www.hackerrank.com/challenges/preprocessor-solution/copy-from/99216490

/* Enter your macros here */
#define INF 1000000
#define io(v) cin >> v
#define toStr(str) #str
#define foreach(v, i) for (int i = 0; i < v.size(); ++i)
#define FUNCTION(f, op) /* nothing */

#define minimum(a, b) a = min(a, b)
#define maximum(a, b) a = max(a, b)

#include <iostream>
#include <vector>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif 

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main(){
	int n; cin >> n;
	vector<int> v(n);
	foreach(v, i) {
		io(v)[i];
	}
	int mn = INF;
	int mx = -INF;
	foreach(v, i) {
		minimum(mn, v[i]);
		maximum(mx, v[i]);
	}
	int ans = mx - mn;
	cout << toStr(Result =) <<' '<< ans;
	return 0;

}

