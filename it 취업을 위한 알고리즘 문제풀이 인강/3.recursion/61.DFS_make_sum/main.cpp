#include <stdio.h>

int a[11], n, m, cnt=0, path[11];

void DFS(int L, int val){

    if(L==n+1){ // 종료조건1 : 마지막 노드 도착 후, 누적 val값 확인
        if(val==m){ 
            cnt++;
            for(int i=1; i<L; i++){
                printf("%d", path[i]);
            }
            puts("");
        }
    }
    else {
        path[L]=a[L];
        DFS(L+1, val+a[L]); // 자식노드1 : 더하는경우
        path[L]=-a[L];
        DFS(L+1, val-a[L]); // 자식노드2 : 빼는 경우
        path[L]=0;
        DFS(L+1, val);  // 자식노드3: 참여하지 않는경우
    }

}

int main(){
    freopen("G:\\Git\\Algorithm-C-\\3.recursion\\61.DFS_make_sum\\input.txt", "rt", stdin);

    scanf("%d %d", &n, &m);

    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }

    DFS(1, 0);

    if(cnt!=0) printf("%d", cnt);
    else printf("-1");
    

    return 0;
}