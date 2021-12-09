#include <iostream>
using namespace std;

int main()
{
    int train[8] = { 3,7,6,4,2,9,1,7 };

    int team[3];

    for (int i = 0; i < 3; i++) {
        cin >> team[i];
    }

    for (int i = 0; i <= 5; i++) {
        if (train[i] == team[0]) {
            if (train[i + 1] == team[1]) {
                if (train[i + 2] == team[2]) {
                    cout << i << "번~" << i + 2 << "번 칸";
                }
            }
        }
    }

    return 0;
}