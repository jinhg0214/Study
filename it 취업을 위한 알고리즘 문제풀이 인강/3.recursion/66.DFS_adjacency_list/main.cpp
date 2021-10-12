#include <stdio.h>
#include <vector>

using namespace std;

// 인접리스트를 이용한 DFS탐색
// 배열보다 메모리, 시간이 절약됨!

int ch[30], cnt=0, n;
vector<int> map[30]; 
// 벡터 '배열' 생성
// index를 출발로, 저장값을 도착지로 사용함
// map[n].size()로 몇개의 노드에 연결되어있는지 확인 가능


void DFS(int v){

    // 종착점에 도달한경우
    if(v==n){
        cnt++;
    } 
    
    else {
        // v와 연결된 노드를 확인
        for(int i=0; i<map[v].size(); i++){
            
            if(ch[ map[v][i] ]==0){    // 벡터는 인덱스로 참조가 가능함
                ch[ map[v][i] ] = 1;
                DFS(map[v][i]);
                ch[ map[v][i] ] = 0;
            }
        }
    }

}


int main(){
    freopen("G:\\Git\\Algorithm-C-\\3.recursion\\66.DFS_adjacency_list\\input.txt","rt", stdin);

    int m, i, start, end;

    scanf("%d %d", &n, &m);

    for(int i=1; i<=m; i++){
        scanf("%d %d", &start, &end);
        map[start].push_back(end); 
    }

    ch[1]=1;
    DFS(1);
    printf("%d\n", cnt);

    return 0;
}