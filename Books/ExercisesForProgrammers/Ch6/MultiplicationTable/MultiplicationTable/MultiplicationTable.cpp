#include <iostream>
#include <vector>

constexpr auto SIZE = 12;

using namespace std;

int main()
{

    for (int i = 0; i <= SIZE; i++) {
        for (int j = 0; j <= SIZE; j++) {
            cout << i << " X " << j << " = " << i * j << endl;
        }
    }

}