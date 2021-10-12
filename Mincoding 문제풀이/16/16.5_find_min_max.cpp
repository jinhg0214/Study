#include <iostream>
using namespace std;


int find_max(char str[]) {
    int max = -21e8;
    int idx = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] > max) {
            max = str[i];
            idx = i;
        }
    }

    return idx;
}

int find_min(char str[]) {
    int min = 21e8;
    int idx = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < min) {
            min = str[i];
            idx = i;
        }
    }

    return idx;
}


int main(){

    char str[20];

    cin >> str;

    // 가장 큰수의 idx와 가장 작은수의 idx찾기
    cout << find_max(str) << endl
        << find_min(str) << endl;

    return 0;
}