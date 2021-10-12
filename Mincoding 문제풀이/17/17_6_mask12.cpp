#include <iostream>
using namespace std;

int main()
{
    int mask[2][4][4] = {
        0,0,0,1,
        1,1,0,1,
        1,0,0,1,
        1,1,1,1,

        1,1,1,1,
        1,0,1,1,
        1,0,0,0,
        1,0,0,0
    };

    int res_mask[4][4] = { 0 };

    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (mask[0][y][x] == 1 || mask[1][y][x] == 1) {
                res_mask[y][x] = 1;
            }
        }
    }

    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (res_mask[y][x] == 0) {
                cout << "(" << y << "," << x<< ")" << endl;
            }
        }
    }

    return 0;
}