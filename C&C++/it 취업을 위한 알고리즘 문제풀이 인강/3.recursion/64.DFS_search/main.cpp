#include <stdio.h>

int map[21][21], chk[21], cnt=0, n;

void DFS(int v){
    // ������������ Ȯ��
    if(v == n){
        cnt++;
    } 
    // �ƴѰ�� ���ȣ��
    else {
        for(int i=1; i<=n; i++){
            if(map[v][i] == 1 && chk[i]==0){ // v to 1��ΰ� �ְ�, �湮���� �ʾҴٸ� 
                chk[i]=1;
                DFS(i);
                chk[i]=0; 
                // üũ�� �ٽ� Ǫ������??
                // �ٸ� ����Լ��� �湮�� �� �ֵ��� üũ ����
            }
        }
    }

}

int main(){
    freopen("G:\\Git\\Algorithm-C-\\3.recursion\\64.DFS_search\\input.txt", "rt", stdin);


    int m, start, end;
    scanf("%d %d", &n, &m);

    for(int i=1; i<=m; i++){
        scanf("%d %d", &start, &end);
        map[start][end] = 1;
    }

    chk[1]=1;
    // 1�� ������ ���
    DFS(1);

    printf("%d", cnt);

    return 0;
}