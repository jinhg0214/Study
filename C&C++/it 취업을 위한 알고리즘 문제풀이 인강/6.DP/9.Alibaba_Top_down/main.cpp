#include <iostream>
#include <algorithm>

/* 
D(2,2) : (0,0)에서 시작해서 (2,2)에 도달하는데 드는 최소 비용
|      \
D(2,1)   D(1,2)
|      \
D(2,0) D(1,1) <- 와 같이 여러번 호출되는곳은 Memoization 
|
D(1,0) 가장자리 도달시 따로 호출 방법 설정

*/

using namespace std;

int arr[21][21], dy[21][21];

int DFS(int x, int y){

    // memoization
    if(dy[x][y] != 0) return dy[x][y];

    // 바닥에 도달
    if(x==0 && y==0) return arr[0][0];
    else{
        // 가장자리인 경우
        if(y==0) return dy[x][y] = DFS(x-1, y) + arr[x][y];
        else if (x==0) return dy[x][y] = DFS(x, y-1) + arr[x][y];
        // 그 외
        else 
            return dy[x][y] = min(DFS(x-1,y) ,DFS(x, y-1)) + arr[x][y];
    }


}

int main(){
    freopen("G:\\Git\\Algorithm-C-\\6.DP\\8.Alibaba_Bottom_up\\input.txt", "rt", stdin);

    int n;

    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    cout << DFS(n-1, n-1) << endl;

    return 0;
}