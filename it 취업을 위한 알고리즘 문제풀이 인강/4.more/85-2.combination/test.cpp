#include <iostream>

using namespace std;

int n, r;
int ch[20];

void DFS(int L, int s){
    if(L == r){ // r ���� ����
        for(int j=0; j<r; j++){ // ���� r���� ���
            cout << ch[j] << " ";
        } cout << endl;
    }
    else{
        for(int i=s; i<n; i++){
            ch[L] = i;  
            DFS(L+1, i+1); // ���� Level�� ���� ���ڸ� �־
        }
    }
}

int main(){

    cin >> n >> r;

    DFS(0, 0);

    return 0;
}