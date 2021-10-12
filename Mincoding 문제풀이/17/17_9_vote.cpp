#include <iostream>
using namespace std;

int main(){
    int vect[3][3] = {
        3,7,4,
        2,2,4,
        2,2,5
    };

    int target[3];

    for (int i = 0; i < 3; i++) {
        cin >> target[i];
    }

    int cnt[3] = { 0 };
    for (int i = 0; i < 3; i++) {
        for (int y = 0; y < 3; y++) {
            for (int x = 0; x < 3; x++) {
                if (vect[y][x] == target[i]) {
                    cnt[i]++;
                }
            }
        }
    }
    
    int max = -21e8;
    int idx;

    for (int i = 0; i < 3; i++) {
        if (max < cnt[i]) {
            max = cnt[i];
            idx = i;
        }
    }

    cout << target[idx];

    return 0;
}