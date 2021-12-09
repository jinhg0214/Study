#include <iostream>

// Top-down 방식
// DFS를 이용

using namespace std;

int DFS(int x){
    if(x == 1 || x==2) return x;
    else {
        return DFS(x-1) + DFS(x-2);
    }

}

int main(){
    int n;

    cin >> n;

    cout << DFS(n);

    return 0;
}