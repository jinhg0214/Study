#include <stdio.h>

int main(){
    freopen("G:\\Git\\Algorithm-C-\\3.recursion\\63.matrix\\input.txt", "rt", stdin);

    int n, m, start, end, weight;
    int matrix[21][21]={0};

    scanf("%d %d", &n, &m);

    for(int i=1; i<=m; i++){
        scanf("%d %d %d", &start, &end, &weight);
        matrix[start][end]=weight;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}