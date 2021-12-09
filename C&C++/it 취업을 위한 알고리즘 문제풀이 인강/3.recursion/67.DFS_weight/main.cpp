#include <stdio.h>
#include <vector>

using namespace std;

int map[30][30], ch[30], n, cost=2147000000;


// ��� ���� sum ���� �Ű������� ����
void DFS(int v, int sum){

    int i;

    if(v==n){ // ��ǥ ��忡 ������ ��� cost�� ���Ѵ�
        if(sum < cost) cost = sum;
    }
    else {
        for(i=1; i<=n; i++){
            if( map[v][i]>0 && ch[i]==0 ){
                ch[i]=1;
                DFS(i, sum + map[v][i] ); // ����ġ ���� sum�� �߰�
                ch[i]=0;
            }
        }

    }

}

int main(){
    freopen("G:\\Git\\Algorithm-C-\\3.recursion\\67.DFS_weight\\input.txt", "rt", stdin);

    int m, i, start, end, weight;

    scanf("%d %d", &n, &m);

    for(i=1; i<=m; i++){
        scanf("%d %d %d", &start, &end, &weight);
        map[start][end] = weight;
    }

    ch[1]=1;
    // 1���� ���, sum=0���� �ʱ�ȭ
    DFS(1, 0);

    printf("%d\n", cost);

    return 0;
}