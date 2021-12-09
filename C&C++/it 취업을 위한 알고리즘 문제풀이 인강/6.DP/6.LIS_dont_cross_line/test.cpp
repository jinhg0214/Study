#include <iostream>
#include <vector>

using namespace std;

/*
최대 선 연결하기
선이 겹치지 않고 최대 몇개의 선을 그을 수 있는지 -> LIS
*/

int main(){
    freopen("G:\\Git\\Algorithm-C-\\6.DP\\6.LIS_dont_cross_line\\input.txt", "rt", stdin);

    int n, res =0;

    cin >> n;

    vector<int> arr(n+1), dy(n+1); 

    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }

    // LIS
    dy[1] = 1;

    for(int i=2; i<=n; i++){
        int max = 0;    // 이전까지의 최대 선의 수를 저장

        for(int j=i-1; j>=1; j--){
            // 자기 앞의 원소들과 비교
            if(arr[j] < arr[i] && dy[j] > max){
                max = dy[j];    
            }
        }
        dy[i] = max + 1;    // 거기에 1을 추가

        if(dy[i] > res) res = dy[i];
    }
    cout << res << endl;

    return 0;
}