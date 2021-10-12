#include <iostream>
using namespace std;

int main(){
    int index0, index1;
    int arr[6];

    cin >> index0 >> index1;

    arr[0] = index0;
    arr[1] = index1;

    for (int i = 2; i < 6; i++) {
        arr[i] = arr[i - 2] * arr[i - 1];
    }

    cout << arr[5];

    return 0;
}