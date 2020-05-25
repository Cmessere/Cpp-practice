//Shiro23

//https://www.hackerrank.com/challenges/c-tutorial-class/copy-from/99511910

#include <bits/stdc++.h>
#include <sstream>

using namespace std;

class Student{
    public:
      string get_first_name() {
           return first;
           }

      void set_first_name(string a) {
          first = a;
          }

      int get_age(){
          return age;
        }
      void set_age(int a) { 
          age = a;
          }

      string get_last_name() {
          return last;
          }

      void set_last_name(string a) {
          last = a;
      }

      int get_standard() {
          return standard;
          }

      void set_standard(int std) {
          standard = std;
          }

      string to_string() { 
          stringstream s;
          s << age << "," << first << "," << last << "," <<standard;
          return s.str();

          }

    private:
      int age;
      string first;
      string last;
      int standard;
};

int main() {
    int age, standard;
    string first_name, last_name;
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}


