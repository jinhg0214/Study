#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int ch[30]; // MST�� ���ԵǾ��ִ��� üũ�ϴ� �迭

struct Edge{ // ���
    int e; // ����� ���
    int val; // ���� ����� ������ ����ġ
    Edge(int a, int b){
        e = a;
        val = b;
    }
    bool operator<(const Edge& b)const{
        return this->val < b.val;
    }
};

int main(){
    freopen("G:\\Git\\Algorithm-C-\\4.more\\79.PrimMST\\input.txt", "rt", stdin);

    int n, m, i, start, end, weight, res=0;
    // vector<pair<int,int> > map[30];
    priority_queue<Edge> Q;

    cin >> n >> m;

    /*
    for(i=1; i<=m; i++){
        cin >> start >> end >> weight;

        // ������ ����
        map[start].push_back(make_pair(end,weight));
        map[end].push_back(make_pair(start,weight));
    }*/

    vector<Edge> map[30]; // ����

    for(i=1; i<=m; i++){
        cin >> start >> end >> weight;

        // ������ ����
        map[start].push_back(Edge(end,weight));
        map[end].push_back(Edge(start,weight));
    }


    // Prim �˰���

    Q.push(Edge(1,0)); // ��� 1���� ����, �ڱ� �ڽŰ��� ����ġ�� 1
    
    while(!Q.empty()){
        Edge tmp = Q.top();
        Q.pop();

        int v = tmp.e;
        int cost = tmp.val;

        if(ch[v]==0){

            res += cost;
            ch[v]=1;

            // ���� ���� ����� ������ ť�� �߰�
            for(i=0; i<map[v].size(); i++){
                Q.push(Edge(map[v][i].e, map[v][i].val));
            }
        }
    }
    cout << res << endl;

    return 0;
}