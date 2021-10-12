#include <iostream>

using namespace std;

void rc(int level, int n, int branch) {
    if (level == n) {
        return;
    }

    else {
        for (int i = 0; i < branch; i++) {
            rc(level + 1, n, branch);
        }
    }
}

int main() {
    int lvl, branch;

    cin >> lvl >> branch;

    rc(0, lvl, branch);

    return 0;
}