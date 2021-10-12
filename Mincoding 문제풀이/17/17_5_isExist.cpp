#include <iostream>
using namespace std;

bool isExist(int map[][3], int n) {

    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            if (map[y][x] == n) {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int map[3][3] = { 
        3,5,9,
        4,2,1,
        5,1,5 
    };

    int input[3];

    for (int i = 0; i < 3; i++) {
        cin >> input[i];
    }

    for (int i = 0; i < 3; i++) {
        cout << input[i];
        if (isExist(map, input[i])) {
            cout << ":존재" << endl;
        }
        else {
            cout << ":미발견" << endl;
        }
    }

    return 0;
}