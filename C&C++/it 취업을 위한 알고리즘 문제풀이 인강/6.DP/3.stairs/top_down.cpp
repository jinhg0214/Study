#include <iostream>

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