//Shiro23

//https://www.hackerrank.com/challenges/cpp-maps/copy-from/151602069

#include <algorithm>
#include <map> 
#include <bits/stdc++.h>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int queries;
    short type, targetValue;
    string targetName;


    map<string, int> gradesMap;

    cin >> queries;

    for(int i =0; i < queries; i++){
        cin >> type;

        switch (type) {
            case 1:
            cin >> targetName >> targetValue;
            if(gradesMap.find(targetName) != gradesMap.end()){
                int temp = gradesMap[targetName] + targetValue;

                gradesMap.erase(targetName);
                gradesMap.insert(make_pair(targetName, temp));
            }
            else{
                gradesMap.insert(make_pair(targetName, targetValue));
            }
            
            break;

            case 2:
            cin >> targetName;

            gradesMap.erase(targetName);
            break;

            case 3:
            cin >> targetName;

            gradesMap.find(targetName) != gradesMap.end() ?
            cout << gradesMap[targetName] <<endl : cout << 0 << "\n";
            break;
        }
    }
    return 0;
}

