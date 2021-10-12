#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    freopen("G:\\Git\\Algorithm-C-\\3.recursion\\69.BFS\\input.txt", "rt", stdin);

    int start, end, x;
    vector<int> map[10];
    int Q[100], ch[10]={0}, front=-1, back=-1; //체크 배열을 0으로 초기화 하지 않은 경우 에러 발생

    // 6개의 간선을 받아 map에 저장
    // 무방향 노드이므로 start->End, end->start를 저장한다
    for(int i=1; i<=6; i++){    
        scanf("%d %d", &start, &end);
        map[start].push_back(end);
        map[end].push_back(start);
    }

    /* map연결리스트 출력
    for(int i=1; i<=6; i++){
        for(int j=0; j<map[i].size(); j++){
            printf("%d ", map[i][j]);
        }
        printf("\n")
    }*/

    // BFS
    // root노드 1 에서 부터 시작
    Q[++back]=1;
    ch[1]=1;

    while(front<back){
        x=Q[++front];
        printf("%d ",x);

        for(int i=0; i<map[x].size(); i++){
            if(ch[ map[x][i] ]==0){
                ch[ map[x][i] ]=1;
                Q[++back]=map[x][i];
            }
        }
    }

    return 0;
}

