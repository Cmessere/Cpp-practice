//Shiro23

//https://www.hackerrank.com/challenges/strange-advertising/problem

#include <bits/stdc++.h>

using namespace std;

int viralAdvertising(int day) {
    int peopleSharing = 5, likes = 0;

    for(int i = 0; i < day; i++){
                peopleSharing = std::floor(peopleSharing/2);
                likes += peopleSharing;
                peopleSharing *= 3;
            }
    
    return likes;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = viralAdvertising(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
