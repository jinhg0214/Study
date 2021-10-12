#include <iostream>

using namespace std;

int main() {
    int a[4], b[4];

    for (int i = 0; i < 4; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < 4; i++) {
        cin >> b[i];
    }

    int sum[4];

    for (int i = 0; i < 4; i++) {
        sum[i] = a[i] + b[3 - i];
    }

    for (int i = 0; i < 4; i++) {
        cout << sum[i] << " ";
    }
    return 0;
}