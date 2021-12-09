#include <iostream>

using namespace std;

int n, r;
int ch[20];

void DFS(int L, int s){
    if(L == r){ // r 개를 뽑음
        for(int j=0; j<r; j++){ // 뽑은 r개를 출력
            cout << ch[j] << " ";
        } cout << endl;
    }
    else{
        for(int i=s; i<n; i++){
            ch[L] = i;  
            DFS(L+1, i+1); // 다음 Level에 다음 숫자를 넣어봄
        }
    }
}

int main(){

    cin >> n >> r;

    DFS(0, 0);

    return 0;
}