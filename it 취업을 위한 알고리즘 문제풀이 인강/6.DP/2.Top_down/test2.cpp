#include <iostream>

// Top-down 방식 2
// DFS를 이용
// + Memoization 

using namespace std;

int dy[50];

int DFS(int x){
    if(dy[x] != 0) return dy[x];
    if(x == 1 || x==2) return x;
    else {
        return dy[x] = DFS(x-1) + DFS(x-2);
    }

}

int main(){
    int n;

    cin >> n;

    cout << DFS(n);

    return 0;
}