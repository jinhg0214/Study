#include <iostream>
#include <string>

using namespace std;

int main() {
    int a, b, c;

    cin >> a >> b >> c;

    for (int i = 0; i < c; i++) {
        for (int j = a; j <= b; j++) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}