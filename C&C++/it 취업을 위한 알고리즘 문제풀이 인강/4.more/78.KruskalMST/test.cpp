#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

struct Edge{
    int start;
    int end;
    int weight;
    Edge(int a, int b, int c){
        start =a;
        end =b;
        weight =c;
    }
    // ������������ ����
    bool operator<(const Edge &b)const{
        return weight < b.weight;
    }
};

int unf[10001];

int Find(int v){
    if(v==unf[v]) return v;
    else return unf[v]=Find(unf[v]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a!=b) unf[a]=b;
}

int main(){
    freopen("G:\\Git\\Algorithm-C-\\4.more\\78.KruskalMST\\input.txt","rt",stdin);

    vector<Edge> Ed;
    int i, n, m, start, end, weight, res=0;

    scanf("%d %d", &n, &m);

    // ���� ������ �ʱ�ȭ
    for(i=1; i<=n; i++){
        unf[i]=i; 
    }

    // vector<Edge>�� ����
    for(i=1; i<=m; i++){
        scanf("%d %d %d", &start, &end, &weight);
        Ed.push_back(Edge(start, end, weight)); 
    }

    // Edge �������� ����
    sort(Ed.begin(), Ed.end());

    // Kruscal �˰��� ����
    for(i=0; i<m; i++){

        int fa=Find(Ed[i].start); // ���� ���
        int fb=Find(Ed[i].end); // ���� ���

        // ����Ŭ�� �������� ���� ���
        if(fa!=fb){
            res+=Ed[i].weight; // ������ ���� �� ��,
            Union(Ed[i].start, Ed[i].end); // ���� ���տ� ���ϵ��� Union ����
        }
    }

    printf("%d", res);

    return 0;
}