#include <iostream>

using namespace std;

int n, m;
int cnt = 0;

void counting(int Lv) {
    
    cnt++;
    if (Lv == m) {
        return;
    }

    for (int x = 0; x < n; x++) {
        counting(Lv + 1);
    }


}

int main(){
    cin >> n >> m;

    counting(0);

    cout << cnt;

    return 0;
}