//Shiro23

//https://www.hackerrank.com/challenges/c-tutorial-struct/copy-from/151604086

#include <string>
#include <bits/stdc++.h>

using namespace std;


    struct Student {
        short age;
        string first_name;
        string last_name;
        short standard;
    } ;

int main() {
    Student st;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> st.age >> st.first_name >> st.last_name >> st.standard;
    cout << st.age << " " << st.first_name << " " << st.last_name << " " << st.standard;
    
    return 0;
}