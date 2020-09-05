//Shiro23

//https://www.hackerrank.com/challenges/c-tutorial-strings/copy-from/151466945

#include <bits/stdc++.h>
#include <string>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

        string string_a = "", string_b = "";

        cin >> string_a >> string_b;

        cout << string_a.size() << " " << string_b.size() << "\n";
        cout << string_a + string_b << "\n";

        char temp_switch = string_a[0];

        string_a[0] = string_b[0];
        string_b[0] = temp_switch;

        cout << string_a << " " << string_b << "\n";

        return 0;
}
