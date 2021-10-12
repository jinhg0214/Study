#include <stdio.h>

int map[8][8]={0}, chk[8][8], cnt=0;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};


void DFS(int x, int y){
    
    int xx, yy;

    if(x==7 && y==7){ //(7,7)에 도착한 경우 
        cnt++;
    } else {
        for(int i=0; i<4; i++){
           xx = x+dx[i];
           yy = y+dy[i];

           // 맵 밖으로 나간 경우 
           if(xx<1 || xx>7 || yy<1 || yy>7){
               continue;
           }

            // 벽이 아니고 && 방문한 기록이 없다면
           if(map[xx][yy]==0 && chk[xx][yy]==0){
               chk[xx][yy] = 1;
               DFS(xx,yy);
               chk[xx][yy] = 0;
           }
        }
    }
}

int main(){
    // freopen("G:\\Git\\Algorithm-C-\\3.recursion\\65.DFS_maze\\input.txt", "rt", stdin);

    for(int i=1; i<=7; i++){
        for(int j=1; j<=7; j++){
            scanf("%d", &map[i][j]);
        }
    }

    chk[1][1]=1; //1,1에서 출발
    DFS(1,1);

    printf("%d", cnt);
}