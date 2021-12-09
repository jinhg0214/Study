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
    // 오름차순으로 정렬
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

    // 연결 포인터 초기화
    for(i=1; i<=n; i++){
        unf[i]=i; 
    }

    // vector<Edge>에 삽입
    for(i=1; i<=m; i++){
        scanf("%d %d %d", &start, &end, &weight);
        Ed.push_back(Edge(start, end, weight)); 
    }

    // Edge 오름차순 정렬
    sort(Ed.begin(), Ed.end());

    // Kruscal 알고리즘 적용
    for(i=0; i<m; i++){

        int fa=Find(Ed[i].start); // 현재 노드
        int fb=Find(Ed[i].end); // 다음 노드

        // 사이클이 형성되지 않은 경우
        if(fa!=fb){
            res+=Ed[i].weight; // 간선을 선택 한 뒤,
            Union(Ed[i].start, Ed[i].end); // 같은 집합에 속하도록 Union 해줌
        }
    }

    printf("%d", res);

    return 0;
}