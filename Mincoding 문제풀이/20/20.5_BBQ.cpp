#include <iostream>

using namespace std;

void BBQ(int lvl) {

    if (lvl == 2) {
        return;
    }
    else {
        BBQ(lvl + 1);
    }

}


int main() {

    BBQ(0);

    return 0;
}