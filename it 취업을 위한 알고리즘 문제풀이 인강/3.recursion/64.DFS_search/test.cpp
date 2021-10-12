#include <stdio.h>

int matrix[21][21], chk[21], cnt=0, n;

void DFS(int v){

    if(v==n){ // ���������� �����Ѱ��
        cnt++;
    }
    else {
        for(int i=1; i<=n; i++){ // �� ������ ����Ǿ��ִ��� Ȯ��
            if(matrix[v][i] == 1 && chk[i] == 0){  // ����Ǿ��ְ�, �湮���� ���� ����ΰ��
                chk[i]=1;
                DFS(i);
                chk[i]=0;
            }
        }
    }
}

int main(){
    // freopen("G:\\Git\\Algorithm-C-\\3.recursion\\64.DFS_search\\input.txt", "rt", stdin);

    int m, start, end;
    scanf("%d %d", &n, &m);

    for(int i=1; i<=m; i++){
        scanf("%d %d", &start, &end);
        matrix[start][end] = 1;
    }

    chk[1]=1;
    DFS(1); // 1���� �����Ͽ� n���� ������ �� �ִ� ����� ��

    printf("%d", cnt);

    return 0;
}