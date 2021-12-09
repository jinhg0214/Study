#include <stdio.h>

/*
1�� 1������ ������, 0�� �׵θ��� �����

1) a i j �� ����
          a[i-1][j]
a[i][j-1] a[i][j] a[i][j+1]
          a[i+1][j]

2) a[i+dx[k]]�� ���� V
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

    // ī����
    for(i=1; i<=n ; i++){
        for(j=1; j<=n; j++){
            flag=0; 

            // �ڽ��� 4������ ���� Ȯ��
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