#include <iostream>
#include <string>

using namespace std;

int main() {
    int y, x;
    char ch;

    cin >> y >> x;
    cin >> ch;

    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                cout << ch;
            }
            cout << endl;
        }
        cout << endl;
    }
   

    return 0;
}