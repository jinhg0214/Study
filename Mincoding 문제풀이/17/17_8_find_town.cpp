#include <iostream>
using namespace std;

int main(){

    char vect[10] = "BTKIGZ";

    char target[5];

    for (int i = 0; i < 4; i++) {
        cin >> target[i];
    }
    

    int cnt = 0;

    for (int t = 0; t < 5; t++) {
        for (int i = 0; vect[i] != '\0'; i++) {
            if (target[t] == vect[i]) {
                cnt++;
            }
        }
    }

    cout << cnt;
    

    return 0;
}