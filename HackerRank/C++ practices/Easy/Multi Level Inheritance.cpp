//Shiro23

//https://www.hackerrank.com/challenges/multi-level-inheritance-cpp/copy-from/99533385

#include <bits/stdc++.h>

using namespace std;

class Triangle{
	public:
		void triangle(){
			cout<<"I am a triangle\n";
		}
};

class Isosceles : public Triangle{
  	public:
  		void isosceles(){
    		cout<<"I am an isosceles triangle\n";
  		}
};

class Equilateral : public Isosceles{
    public:
    void equilateral(){
        cout << "I am an equilateral triangle\n";
    }
};
//Write your code here.

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Equilateral eqr;
    eqr.equilateral();
    eqr.isosceles();
    eqr.triangle();
    return 0;
}


