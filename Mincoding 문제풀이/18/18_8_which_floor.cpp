#include <iostream>
using namespace std;

int apt[5][3] = {
       15,18,17,
       4,6,9,
       10,1,3,
       7,8,9,
       15,2,6
};

// apt배열의 y층에, arr이 존재하는지 확인하는 함수
bool isPattern(int y, int arr[]) {

    for (int x = 0; x < 3; x++) {
        if (apt[y][x] == arr[0]) {
            if (apt[y][x + 1] == arr[1]) {
                if (apt[y][x + 2] == arr[2]) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
   

    int family[3];

    for (int i = 0; i < 3; i++) {
        cin >> family[i];
    }

    for (int y = 0; y < 5; y++) {
        if (isPattern(y, family) == true) {
            cout << 5 - y << "층";
        }
    }


    return 0;
}