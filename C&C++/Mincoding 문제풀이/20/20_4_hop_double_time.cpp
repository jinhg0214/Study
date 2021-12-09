#include <iostream>

using namespace std;

int n;

void abc(int lvl) {
    if (lvl == n+6) {
        cout << lvl << " ";
        return;
    }
    else {
        abc(lvl + 2);
        cout << lvl << " ";
    }
}

int main() {
    cin >> n;

    abc(n);

    return 0;
}