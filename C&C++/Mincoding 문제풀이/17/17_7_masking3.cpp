#include <iostream>
using namespace std;

int main()
{
    int arr[2][2][5]= {
        0,0,0,0,0,
        0,0,0,0,0,

        3,5,4,1,1,
        3,5,2,5,6
    };

    int mask[2][5] = {
        0,0,1,0,0,
        0,0,1,1,1
    };

    int n;
    bool flag = 0;

    cin >> n;


    for (int i = 0; i < 2; i++) {
        for (int y = 0; y < 2; y++) {
            for (int x = 0; x < 5; x++) {
                // 마스크가 겹치는 부분중에, 입력받은 숫자가 존재한다면 flag 1
                if (mask[y][x] == 1 && arr[i][y][x] == n) {
                    flag = 1;
                }
            }
        }
    }

    if (flag == 1) {
        cout << n << " 존재";
    }
    else {
        cout << n << " 없음";
    }

    

    return 0;
}