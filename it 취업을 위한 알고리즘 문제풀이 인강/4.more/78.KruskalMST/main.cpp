#include <stdio.h>
#include <vector>
#include <algorithm>

/*
그래프에서 최소 비용 트리를 만드는 문제
N개의 노드 -> n-1개의 간선 필요. Kruskal 알고리즘 사용.

[Kruskal 알고리즘]
1. 간선의 가중치를 오름차순으로 정렬
2. 간선을 선택해가며 기록, Cycle이 되면 선택 불가!
*/

using namespace std;
int unf[10001];

// 간선 정보 저장
struct Edge{
    int v1; 
    int v2;
    int val;
    Edge(int a, int b, int c){
        v1=a;
        v2=b;
        val=c;
    }

    bool operator<(Edge &b){ // 정렬 기준은 가중치 오름차순으로
        return val<b.val;
    }
};

int Find(int v){
    if(v==unf[v]) return v;
    else return unf[v]=Find(unf[v]);  // 배열에 memoization
}

void Union(int a, int b){
    a=Find(a);
    b=Find(b);
    if(a!=b) unf[a]=b;
}

int main(){
    freopen("G:\\Git\\Algorithm-C-\\4.more\\78.KruskalMST\\input.txt","rt",stdin);
    vector<Edge> Ed;

    int i, n, m, a, b, c, cnt=0, res=0;

    scanf("%d %d", &n, &m);

    for(i=1; i<=n; i++){
        unf[i]=i;
    }

    for(i=1; i<=m; i++){
        scanf("%d %d %d", &a, &b, &c);
        Ed.push_back(Edge(a,b,c));
    }

    sort(Ed.begin(), Ed.end());

    for(i=0; i<m; i++){
        int fa = Find(Ed[i].v1);
        int fb = Find(Ed[i].v2);
        if(fa!=fb){
            res+=Ed[i].val;
            Union(Ed[i].v1, Ed[i].v2);
        }
    }

    printf("%d", res);

    return 0;
}