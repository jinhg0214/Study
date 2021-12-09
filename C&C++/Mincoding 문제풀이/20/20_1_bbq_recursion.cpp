#include <iostream>

using namespace std;

void bbq(int lvl) {
    if (lvl == 3) {
        return;
    }
    else {
        bbq(lvl + 1);
    }
}

int main() {
    bbq(0);

    return 0;
}