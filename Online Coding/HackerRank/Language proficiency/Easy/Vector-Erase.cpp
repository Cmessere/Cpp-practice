//Shiro23

//https://www.hackerrank.com/challenges/vector-erase/problem

#include <vector>
#include <algorithm>

#include <bits/stdc++.h>
using namespace std;

void eraseSingleEntry(vector<int> &vect, int indexToErase){
    const int zeroIndexOffset = 1;
    
    vect.erase (vect.begin()+(indexToErase-zeroIndexOffset));
}

void eraseRangeEntries(vector<int> &vect, int rangeStart, int rangeEnd){
    const int zeroIndexOffset = 1;

    vect.erase (vect.begin()+rangeStart-zeroIndexOffset, vect.begin()   +rangeEnd-zeroIndexOffset);

}

void printVectorSizeAndValues(vector<int> &vect){
    cout << vect.size() << endl;

    for ( auto i = vect.begin(); i != vect.end(); ++i)
       cout << *i << ' ';
}

void populateVector(vector<int> &vect, int size){
    int temp;

    for (int i = 0; i < size; i++) {
        cin >> temp;

        vect.push_back(temp);
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int vectorSize, singleIndex, rangeStart, rangeEnd;

    cin >> vectorSize;

    vector<int> vect;

    populateVector(vect, vectorSize);

    cin >> singleIndex >> rangeStart >> rangeEnd;

    eraseSingleEntry(vect, singleIndex);
    eraseRangeEntries(vect, rangeStart,rangeEnd);

    printVectorSizeAndValues(vect);

    return 0;
}

