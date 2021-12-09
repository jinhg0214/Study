#include <iostream>

using namespace std;

int main() {
    int arr[4][5] = {
        3,5,4,2,5,
        3,3,3,2,1,
        3,2,6,7,8,
        9,1,1,3,2
    };

    int y_size, x_size;

    cin >> y_size >> x_size;

    int sum = 0;
    int max = 0, res_y, res_x;

    // 틀을 이동하면서 최대값 계산
    for (int y = 0; y <= 4 - y_size; y++) {
        for (int x = 0; x <= 5 - x_size; x++) {
            
            // 여기 사각형 안의 값들을 더함
            sum = 0;

            // 틀 내에서 sum을 계산
            for (int i = 0; i < y_size; i++) {
                for (int j = 0; j < x_size; j++) {
                    sum += arr[y+i][x+j];
                }
            }

            // 최대값 갱신 및 좌표 저장
            if (sum > max) {
                max = sum; 
                res_y = y;
                res_x = x;
            }
        }
    }

    cout << "(" << res_y << "," << res_x << ")";
    return 0;
}