#include <iostream>

using namespace std;

int main() {
    char ch;
    cin >> ch;

    char arr[3][3] = { 0 };
    int y=2, x=0;
    int i=0;

    while ( y>=0 ) {
        x = 0;
        while (x<=2) {  
            if (x + y <= 2) {
                arr[y][x] = ch + i;
                i++;
            }
            x++;
        }
        y--;
    }

    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            if (arr[y][x] != '\0') {
                cout << arr[y][x];
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}