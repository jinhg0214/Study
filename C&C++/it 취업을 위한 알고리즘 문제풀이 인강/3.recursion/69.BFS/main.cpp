#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int Q[100], front=-1, back=-1, ch[10];
vector<int> map[10];

int main(){
    freopen("G:\\Git\\Algorithm-C-\\3.recursion\\69.BFS\\input.txt", "rt", stdin);

    int i, a, b, x;

    for(i=1; i<=6; i++){
        scanf("%d %d", &a, &b);
        // 방향이 없으므로 a->b, b->a 를 추가
        map[a].push_back(b); 
        map[b].push_back(a);
    }
    
    //큐를 이용하여 BFS탐색
    Q[++back]=1; // root
    ch[1]=1;

    while(front<back){
        x=Q[++front];
        printf("%d ", x);

        // x와 연결된 노드를 큐에 삽입
        for(i=0; i<map[x].size(); i++){
            if(ch[ map[x][i]] == 0){
                ch[map[x][i]]=1;    // 방문 예정
                Q[++back]=map[x][i];
            }
        }
    }

    return 0;
}