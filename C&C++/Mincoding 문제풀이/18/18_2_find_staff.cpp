#include <iostream>

using namespace std;

int main() {
    int cnt[65535] = { 0 };

    int att[12] = { 65000, 35, 42, 70, 70, 35, 65000, 1300, 65000, 30000, 38, 42 };

    for (int i = 0; i < 12; i++) {
        cnt[att[i]]++;
    }

    int maxi=0;
    for (int i = 0; i < 65535; i++) {
        if (cnt[i] > cnt[maxi]) {
            maxi = i;
        }
    }

    cout << maxi;

    return 0;
}