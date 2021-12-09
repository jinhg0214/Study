#include <iostream>

using namespace std;

int n, r;
int ch[20];

// nCr 
void DFS(int s, int L){
    if(L==r){
        for(int j=0; j<L; j++){
            cout << ch[j] << " ";
        }
        cout << endl;
    }
    else{ // 
        for(int i=s; i<n; i++){
            ch[L]=i;    // ch 배열에 i 값을 저장, 
            DFS(i+1, L+1);
        }
    }
}

int main(){
    cin >> n >> r;

    DFS(0, 0);

    return 0;
}