#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int main(){

    int n, m, start, end, tmp;
    int ch[30]={0}, dis[30]={0};
    vector<int> map[30];
    queue<int> q;

    scanf("%d %d",  &n, &m);

    for(int i=1; i<=m; i++){
        scanf("%d %d", &start, &end);
        map[start].push_back(end);
    }

    // BFS
    
    q.push(1);  // 1번 노드부터 시작
    ch[1]=1;    

    while(!q.empty()){
        tmp = q.front();
        q.pop();

        for(int i=0; i<map[tmp].size(); i++){
            if(ch[ map[tmp][i] ]==0){
                ch[ map[tmp][i] ]=1;
                q.push(map[tmp][i]);
                dis[  map[tmp][i] ]= dis[tmp]+1;
            }
        }
    }

    for(int i=2; i<=n; i++){
        printf("%d : %d\n", i, dis[i]);
    }

    return 0;
}