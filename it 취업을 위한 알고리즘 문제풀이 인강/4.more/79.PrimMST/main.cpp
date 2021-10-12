#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>

/*
Kruskal �˰����� ������ �߰��ϴ� ����̶��,
Prim �˰����� ������ �߰��ϴ� ���
������ ������ ���� ��, �׷����� ������踦 ���鼭 Ʈ���� ������ �߰��ϸ� Ȯ����
������ N���� �Ǹ� ����

Prim �˰���

1. ���� ��� �ϳ� ����. MST�� ����.
2. MST�� �� ��尡 �ִ��� Ȯ�� ��, �� ���� ����� �������� �켱���� ť�� ����.
3. �ּ� ����ġ ������ ����. �̸� MST�� ���� 
... ������ n-1���� �ɶ����� 2�� ���ư��� �ݺ���
*/

using namespace std;

int ch[30]; // MST�� ���ԵǾ��ִ��� üũ�ϴ� �迭

struct Edge{
    int e;
    int val;
    Edge(int a, int b){
        e=a;
        val=b;
    }
    bool operator<(const Edge &b)const{
        return val < b.val;
    }
};

int main(){
    freopen("G:\\Git\\Algorithm-C-\\4.more\\79.PrimMST\\input.txt", "rt", stdin);

    priority_queue<Edge> Q;
    vector<pair<int, int> > map[30]; // ��������Ʈ �̿�

    int i, n, m, a, b, c, res=0;

    scanf("%d %d", &n, &m);
    
    // ��������Ʈ�� �̿��Ͽ� ������ �׷��� ����
    for(i=1; i<=m; i++){
        scanf("%d %d %d", &a, &b, &c);
        map[a].push_back(make_pair(b,c));
        map[b].push_back(make_pair(a,c));
    }

    // Prim �˰��� ����
    Q.push(Edge(1,0)); // 1���� ����

    while (!Q.empty()){
        Edge tmp = Q.top(); // �켱���� ť�� top ���� �ּҰ���
        Q.pop();

        int v = tmp.e;
        int cost = tmp.val;

        if(ch[v]==0){ // MST�� ���� ���Ե��� �ʾҴٸ�
            res+= cost; // top�� ����ġ�� �߰���
            ch[v]=1;

            // �� ���� ����� �������� ��� �켱���� ť�� �����Ѵ�
            for(i=0; i<map[v].size(); i++){
                Q.push(Edge(map[v][i].first, map[v][i].second));
            }
        }
    }
    printf("%d\n", res);

    return 0;
}