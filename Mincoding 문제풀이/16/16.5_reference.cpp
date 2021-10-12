#include <iostream>
using namespace std;


struct pos {
    int y, x;
};

pos find_max(int arr[][3]) {
    pos t = { 0,0 };

    int max = -21e8;
    for (int y = 0; y < 2; y++) {
        for (int x = 0; x < 3; x++) {
            if (max < arr[y][x]) {
                max = arr[y][x];
                t.y = y;
                t.x = x;
            }
        }
    }

    return t;
}

pos find_min(int arr[][3]) {
    pos t = { 0,0 };

    int min = 21e8;
    for (int y = 0; y < 2; y++) {
        for (int x = 0; x < 3; x++) {
            if (min > arr[y][x]) {
                min = arr[y][x];
                t.y = y;
                t.x = x;
            }
        }
    }

    return t;
}

int main(){
    int arr[2][3];

    for (int y = 0; y < 2; y++) {
        for (int x = 0; x < 3;x++) {
            cin >> arr[y][x];
        }
    }

    pos p_max, p_min;
    p_max = find_max(arr);
    p_min = find_min(arr);

    cout << "(" << p_max.y << "," << p_max.x << ")" << endl
        << "(" << p_min.y << "," << p_min.x << ")" << endl;

    return 0;
}