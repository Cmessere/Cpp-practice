//Shiro23

//https://www.hackerrank.com/challenges/virtual-functions/copy-from/99531950

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person{
    public:
    virtual void getdata(){}
    virtual void putdata(){}

    protected:
    int age;
    static int id;
    string name;

    //virtual ~Person(){};
};

class Professor : public Person{
    public:
    Professor(){
        cur_id = id++;
    }
     void getdata() {
        cin >> name >> age >> publications;
     }
    void putdata() {
      cout << name << " " << age << " " << publications << " " << cur_id << endl;
    }

    private:
    static int id;
    int publications, cur_id;
};

class Student : public Person{
    public:
    Student(){
        cur_id = id++;
    }
    void getdata(){
        cin >> name >> age;
        for(int i = 0; i < 6; i++){
            cin >> marks[i];
            sum += marks[i];
            }
    }

    void putdata(){
      cout << name << " " << age << " " << sum << " " << cur_id
           << endl;
    }

    private:
    static int id;
    int marks[6], sum = 0, cur_id;
};

int Professor::id = 1;
int Student::id = 1;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
