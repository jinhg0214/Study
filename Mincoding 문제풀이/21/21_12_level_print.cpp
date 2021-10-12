#include <iostream>

using namespace std;

int n;

void asdf(int Lv) {

    cout << Lv;

    if (Lv == n) {
        return;
    }

    for (int x = 0; x < 2; x++) {
        asdf(Lv + 1);
    }

}

int main(){

    cin >> n;

    asdf(0);

    return 0;
}