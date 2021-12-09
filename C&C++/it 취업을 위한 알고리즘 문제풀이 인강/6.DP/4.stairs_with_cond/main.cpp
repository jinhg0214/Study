#include <iostream>

/*
만약 디딜수 없는 계단이 존재하는 경우
dp[x] = 0;하면됨
dp[x+1] = dp[x] + dp[x-1];이 됨
            ↑ 0 */

using namespace std;

int dp[46] = {0};

int DFS(int n){
    if(dp[n] != 0) return dp[n];
    if(n == 1) return 1;
    if(n == 2) return 2;
    else return dp[n] = DFS(n-2) + DFS(n-1);
}

int main(){
    int n;
    cin >> n;

    cout << DFS(n) << endl;

    return 0;
}