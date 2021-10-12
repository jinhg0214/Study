#include <stdio.h>

/*
1행 1열부터 넣을것, 0은 테두리로 사용함

1) a i j 로 제어
          a[i-1][j]
a[i][j-1] a[i][j] a[i][j+1]
          a[i+1][j]

2) a[i+dx[k]]로 제어 V
dx[4] = {-1, 0, 1 ,0}
dy[4] = {0, 1, 0, -1}


*/
int a[51][51];
int dx[4] = {-1, 0 , 1, 0};
int dy[4] = {0, 1, 0 ,-1};

int main(){
    freopen("G:\\Git\\Algorithm-C-\\2.sort\\47.Peak\\input.txt", "rt" ,stdin);

    int n, i, j, k, cnt=0, flag;

    scanf("%d", &n);

    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            scanf("%d", &a[i][j]);
        }
    }

    // 카운팅
    for(i=1; i<=n ; i++){
        for(j=1; j<=n; j++){
            flag=0; 

            // 자신의 4방향을 보며 확인
            for(k=0; k<4; k++){
                if(a[i][j] <= a[i+dx[k]][j+dy[k]]){
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