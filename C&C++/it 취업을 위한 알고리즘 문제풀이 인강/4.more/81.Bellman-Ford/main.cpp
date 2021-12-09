#include <stdio.h>
#include <vector>

using namespace std;

/* ���� ���� ���� ����, ���� ������ ���µ� ��� ���
    1   2   3   4   5   
    0   INF INF INF INF
1   0   5   4   INF INF (���� �ѹ� �̿��)
2   0   5   2   9   18  (�ι�) 
3   0   5   2   7   16
4   0   5   2   7   14

*/

int dist[101];

struct Edge{
    int s;
    int e;
    int val;
    Edge(int a, int b, int c){
        s=a;
        e=b;
        val=c;
    }
};

int main(){
    freopen("G:\\Git\\Algorithm-C-\\4.more\\81.Bellman-Ford\\input.txt", "rt", stdin);
    vector<Edge> Ed;    

    int n, m, i, j, a, b, c, s, e;
    scanf("%d %d", &n, &m);

    // ���Ϳ� ���� ������ ����
    for(i=1; i<=m; i++){
        scanf("%d %d %d", &a, &b, &c);
        Ed.push_back(Edge(a,b,c));
    }

    // dist �迭 INF�� �ʱ�ȭ
    for(i=1; i<=n; i++){
        dist[i] = 2147000000;
    }

    // ��� ���� ��� ����
    scanf("%d %d", &s, &e);

    // Bellman-ford �˰��� ����
    dist[s]=0; // ��� ����

    // i : i������ ������ �� �ִ� ����
    for(i=1; i<n; i++){
        for(j=0;j<Ed.size(); j++){ // �� ���� ����� ���� Ȯ��
            int u=Ed[j].s; // u : ���
            int v=Ed[j].e; // v : ����
            int w=Ed[j].val;

            // ��� + ����ġ �� ���� v�� �� 
            if(dist[u]!=2147000000 && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;    // ���� ����
            }
        }
    }

    // ���� ����Ŭ�� �����ϴ��� Ȯ��
    for(j=0; j<Ed.size(); j++){
        int u=Ed[j].s; // u : ���
        int v=Ed[j].e; // v : ����
        int w=Ed[j].val;

        if(dist[u]!=2147000000 && dist[u] + w < dist[v]){
            printf("-1\n");
            return -1;
        } 
    }
    printf("%d\n", dist[e]);

    return 0;
}