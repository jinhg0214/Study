#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

int main(){
    
    int n, i, j, k, flag, cnt=0;

    scanf("%d", &n);

    vector<vector<int>> map(n+2,vector<int>(n+2,0)); // (행,열)

    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            scanf("%d", &map[i][j]);
        }
    }

    // 카운팅
    for(i=1; i<=n ; i++){
        for(j=1; j<=n; j++){
            flag=0; 

            // 자신의 4방향을 보며 확인
            for(k=0; k<4; k++){
                if(map[i][j] <= map[i+dx[k]][j+dy[k]]){
                    flag=1;
                    break;
                }
            }

            if(flag==0){
                cnt++;
            }
        }
    }
    printf("%d\n", cnt);

    return 0;

}