#include<iostream>
using namespace std;

int main(){
    char arr[6][3];
    int i = 0;

    for (int x = 2; x >= 0; x--) {
        for (int y = 5; y >= 0; y--) {
            arr[y][x] = 'A' + i;
            i++;
        }
    }

    int n, m;

    cin >> n >> m;

    cout << arr[n][m];

    return 0;
}