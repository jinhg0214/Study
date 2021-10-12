#include <iostream>
using namespace std;

int main()
{
    int arr[3][3] = {
        3,5,9,
        4,2,1,
        1,1,5
    };

    int mask[3][3];

    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            cin >> mask[y][x];
        }
    }
    int sum = 0;
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            if (mask[y][x] == 1) {
                sum += arr[y][x];
            }
        }
    }

    cout << sum;

    return 0;
}