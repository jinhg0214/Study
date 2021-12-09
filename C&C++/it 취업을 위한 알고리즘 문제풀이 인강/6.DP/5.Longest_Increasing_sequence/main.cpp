#include <iostream>
#include <vector>

using namespace std;

/*
arr : 수를 저장
dy : arr[n]이 마지막 항일 때, 가장 긴 수열을 저장
*/

int main(){
    freopen("G:\\Git\\Algorithm-C-\\6.DP\\5.Longest_Increasing_sequence\\input.txt", "rt", stdin);

    int n, res=0;
    cin >> n;

    vector<int> arr(n+1), dy(n+1);

    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }

    dy[1] = 1;
    
    for(int i=2; i<=n; i++){
        int max = 0;
        
        for(int j=i-1; j>=1; j--){
            if(arr[j] < arr[i] && dy[j] > max){ // 자기보다 수가 작으면서,dy 값이 가장 큰 값을 max로
                max = dy[j]; 
            }
        }
        dy[i] = max+1;

        if(dy[i] > res) res = dy[i];
    }
    cout << res << endl;

    return 0;
}