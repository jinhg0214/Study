#include <stdio.h>
#include <queue>

/*
                   |5|
       |4|         |6|         |10|
    |3||5||9|   |5||7||11|  |9||11||15|
    ...
    14가 나올때까지 BFS 탐색
    중복을 체크해서 가지가 뻗어나가지 않게(시간복잡도 줄이기 위해)

*/

using namespace std;

int ch[10001]; // 방문한 경우 체크
int d[3]={-1, +1, +5}; // 이동 방향

int main(){

    int s, e, x, pos;
    scanf("%d %d", &s, &e);

    queue<int> q;

    ch[s]=1; //s부터 시작
    q.push(s);

    while(!q.empty()){
        x=q.front();
        q.pop();

        // x에서 이동할 수 있는 좌표
        for(int i=0; i<3; i++){
            pos = x+d[i];
            if(pos<=0 || pos>10000){
                continue;
            }

            // 도착지점인 경우
            if(pos == e){
                printf("%d\n",ch[x]);
                return 0;
            }

            // 도착 지점이 아니고, 한번도 방문하지 않은 경우
            if(ch[pos]==0){
                ch[pos]=ch[x]+1; // 점프의 최소 횟수를 기록. 이전 좌표의 최소횟수 +1
                q.push(pos); 
            }
        }
    }

    return 0;
}