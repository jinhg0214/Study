#include <iostream>

using namespace std;


char arr[6];

void reverse(int lvl) {
    if (lvl == 5) {
        cout << endl;
        return;
    }
    else {
        cout << arr[lvl];
        reverse(lvl + 1);
        cout << arr[lvl];
    }

}

int main() {

    cin >> arr;

    reverse(0);

    return 0;
}