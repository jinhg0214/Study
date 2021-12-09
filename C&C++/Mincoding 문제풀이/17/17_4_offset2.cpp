#include <iostream>
using namespace std;

int main()
{
    char map[3][4] = {
        'A','T','K','B',
        'C','Z','F','D',
        'H','G','E','I'
    };

    char ch;
    int off_y, off_x;

    cin >> ch >> off_y >> off_x;

    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 4; x++) {
            if (map[y][x] == ch) {
                cout << map[y + off_y][x + off_x];
            }
        }
    }
    

    return 0;
}