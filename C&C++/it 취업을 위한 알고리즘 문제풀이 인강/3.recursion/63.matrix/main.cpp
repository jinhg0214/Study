#include <stdio.h>

int map[21][21];

int main(){
    freopen("G:\\Git\\Algorithm-C-\\3.recursion\\63.matrix\\input.txt", "rt", stdin);

    int n, m;
    int start, end, weight;

    scanf("%d %d", &n, &m);

    for(int i=1; i<=m; i++){
        scanf("%d %d %d", &start, &end, &weight);
        map[start][end] = weight;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            printf("%d ", map[i][j]);
        }printf("\n");
    }



    return 0;
}