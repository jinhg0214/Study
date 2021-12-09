#include <stdio.h>
#include <queue>

using namespace std;



int main(){

    int start, end, x, pos;
    int ch[10001];  // 방문체크 배열
    int d[3]={-1, +1, +5};

    queue<int> q;

    scanf("%d %d", &start, &end);

    ch[start]=1;
    q.push(start);

    while(!q.empty()){
        x =  q.front();
        q.pop();

        for(int i=0; i<3; i++){
            pos = x+d[i];

            if(pos > 10001 || pos < 1) continue;
            if(pos == end){
                printf("%d\n", ch[x]);
                return 0;
            }

            if(ch[pos] == 0){
                ch[pos] = ch[x]+1;
                q.push(pos);
            }


        }
    }
}