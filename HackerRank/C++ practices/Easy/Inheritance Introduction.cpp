//Shiro23

//https://www.hackerrank.com/challenges/inheritance-introduction/copy-from/99533309

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
  		void description(){
            cout <<"In an isosceles triangle two sides are equal\n";
          }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Isosceles isc;
    isc.isosceles();
  	isc.description();
    isc.triangle();
    return 0;
}
