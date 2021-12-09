#include <iostream>
#include <vector>

using namespace std;

int main(){
    freopen("G:\\Git\\Algorithm-C-\\6.DP\\5.Longest_Increasing_sequence\\input.txt", "rt", stdin);

    int n, res=0, max;

    cin >> n;

    vector<int> arr(n+1), dy(n+1);

    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }

    dy[1] = 1;

    for(int i=2; i<=n; i++){
        max = 0;

        for(int j=i-1; j>=1; j--){
            if(arr[j] < arr[i] && dy[j] > max)
                max = dy[j];
        }

        dy[i] = max + 1;

        if(dy[i] > res) res = dy[i];
    }
    
    cout << res << endl;

    return 0;
}