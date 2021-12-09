#include <iostream>

using namespace std;

void recursion(int level, int n){

    cout << level;

    if (level == n) {
        return;
    }
    else {
        recursion(level + 1, n);
        recursion(level + 1, n);
    }
}

int main() {
    int n;

    cin >> n;

    recursion(0, n);

    return 0;
}