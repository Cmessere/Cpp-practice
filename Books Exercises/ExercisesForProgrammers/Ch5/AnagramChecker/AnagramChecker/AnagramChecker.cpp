#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <algorithm>

constexpr auto CHAR_VECTOR = 90;

using namespace std;

bool isAnagram(const string& first, const string& second);

bool isAnagram(const string& first, const string& second) {
    vector<int> charCount(CHAR_VECTOR, 0);
    int sum = 0;

    if (first.size() != second.size())
        return false;

    for (auto c : first) {
        charCount[c]++;
    }

    for (auto c : second) {
        charCount[c]--;
    }

    for (auto i : charCount) {
        sum += i;
    }

    if (sum == 0)
        return true;

    return false;
}

void getString(const string& question, string& input) {
    cout << "Enter the " << question << " string: ";
    cin >> input;

    std::for_each(input.begin(), input.end(), [](char& c) {c = ::toupper(c); });
}

int main()
{
    string first, second;
    bool result;


    cout << "Enter two strings and I'll tell you if they are anagrams : " << endl;
    
    getString("first", first);
    getString("second", second);

    result = isAnagram(first, second);

    result ? cout << "\"" << first << "\" and \"" << second << "\" are anagrams" :
        cout << "\"" << first << "\" and \"" << second << "\" are not anagrams";

}