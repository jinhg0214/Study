#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    freopen("G:\\Git\\Algorithm-C-\\2.sort\\46.multitask\\input.txt", "rt", stdin);
    int n, k, pos=0, cnt=0 ,total=0;

    scanf("%d", &n);

    vector<int> task(n+1);


    for(int i=1; i<=n; i++){
        scanf("%d", &task[i]);
        total+=task[i]; // 전체 시간
    }

    scanf("%d", &k);

    // 정전 이전에 모든 작업이 끝남
    if(k>=total){
        printf("-1");   
        return 0;
    }

    while(1){
        pos++;

        if(pos>n) pos=1;

        if(task[pos] == 0){
            continue;
        }

        task[pos]--;
        cnt++; // 초 계산

        // 정전
        if(cnt == k){
            break;
        }
    }

    // 마지막 작업을 한 지점에서 종료됨
    while(1){
        pos++;
        if(pos>n) pos=1;

        // 남아있는 작업 탐색
        if(task[pos] != 0){
            break;
        }
    }
    
    printf("%d\n", pos);

    return 0;

}