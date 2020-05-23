//Shiro23

//https://www.hackerrank.com/challenges/time-conversion/problem

#include <bits/stdc++.h>
#include <string>

using namespace std;


string timeConversion(string s) {
    string hour = s.substr(0,2);

    int hourAsInt;

    if (s.find("PM") != std::string::npos) { 

        if (stoi(hour) < 12) {
            hourAsInt = stoi(hour) + 12;
            hour = to_string(hourAsInt);
        }
        else{
            hourAsInt = stoi(hour);
        }
    }
    else{
        if(hour == "12"){
            hour = "00";
        }
    }

    return hour + s.substr(2,6);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

