#include <iostream>

using namespace std;

int map[21][21], dy[21][21];

int DFS(int x, int y){
    if( dy[x][y] != 0) return dy[x][y];
    if(x==1 && y==1) return map[1][1]; 
    else {
        if(x == 1) return dy[x][y] = DFS(x, y-1) + map[x][y];
        else if(y == 1) return dy[x][y] = DFS(x-1, y) + map[x][y];
        else 
            return dy[x][y] = min(DFS(x-1, y), DFS(x, y-1)) + map[x][y];

    }


}

int main(){
    freopen("G:\\Git\\Algorithm-C-\\6.DP\\8.Alibaba_Bottom_up\\input.txt", "rt", stdin);

    int n;

    cin >> n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> map[i][j];
        }
    }

    cout << DFS(n,n) << endl;

    return 0;
}