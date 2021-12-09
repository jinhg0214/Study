#include <iostream>

using namespace std;

int n, a[11], op[4];
int maxi = -2147000000, mini =2147000000;

void DFS(int L, int sum){
    if(L == n){
        if(sum > maxi) maxi = sum;
        if(sum < mini) mini = sum;
    } 
    else {
        if(op[1] > 0){
            op[1]--;
            DFS(L+1, sum + a[L+1]); // 다음 레벨의 값을 사칙연산 해봄
            op[1]++;
        }
        if(op[2] > 0){
            op[2]--;
            DFS(L+1, sum - a[L+1]);
            op[2]++;
        }
        if(op[3] > 0){
            op[3]--;
            DFS(L+1, sum * a[L+1]);
            op[3]++;
        }
        if(op[4] > 0){
            op[4]--;
            DFS(L+1, sum / a[L+1]);
            op[4]++;
        }
    }
}

int main(){
    freopen("G:\\Git\\Algorithm-C-\\4.more\\85.DFS_numerical_expression\\input.txt", "rt", stdin);


    // 수열 개수
    cin >> n;

    // 수열 입력
    for(int i=1; i<=n; i++){ 
        cin >> a[i];
    }

    // 연산자 개수 
    for(int i=1; i<=4; i++){
        cin >> op[i];
    }

    // DFS
    DFS(1, a[1]); // a[1]부터 시작 Lvl.1

    cout << maxi << endl << mini;

    return 0;
}