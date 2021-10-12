#include <iostream>
using namespace std;

void abc(int lvl) {
    if (lvl == 2) {
        return;
    }
    else {
        for (int i = 0; i < 3; i++) {
            abc(lvl + 1);
        }
    }
}

int main() {

    abc(0);

    return 0;
}