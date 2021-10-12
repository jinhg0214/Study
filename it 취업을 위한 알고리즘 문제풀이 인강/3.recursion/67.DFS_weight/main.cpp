#include <stdio.h>
#include <vector>

using namespace std;

int map[30][30], ch[30], n, cost=2147000000;


// 출발 노드와 sum 값을 매개변수로 받음
void DFS(int v, int sum){

    int i;

    if(v==n){ // 목표 노드에 도착한 경우 cost를 비교한다
        if(sum < cost) cost = sum;
    }
    else {
        for(i=1; i<=n; i++){
            if( map[v][i]>0 && ch[i]==0 ){
                ch[i]=1;
                DFS(i, sum + map[v][i] ); // 가중치 값을 sum에 추가
                ch[i]=0;
            }
        }

    }

}

int main(){
    freopen("G:\\Git\\Algorithm-C-\\3.recursion\\67.DFS_weight\\input.txt", "rt", stdin);

    int m, i, start, end, weight;

    scanf("%d %d", &n, &m);

    for(i=1; i<=m; i++){
        scanf("%d %d %d", &start, &end, &weight);
        map[start][end] = weight;
    }

    ch[1]=1;
    // 1에서 출발, sum=0으로 초기화
    DFS(1, 0);

    printf("%d\n", cost);

    return 0;
}