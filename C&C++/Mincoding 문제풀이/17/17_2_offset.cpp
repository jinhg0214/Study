#include <iostream>
using namespace std;

int main()
{
    int arr[8] = {
        5,9,4,6,1,5,8,9
    };

    int idx, target;
    int offset = 0;

    cin >> idx >> target;

    for (int i = idx; i < 8; i++) {
        if (arr[i] == target) {
            cout << offset;
            break;
        }
        else {
            offset++;
        }
    }

    return 0;
}