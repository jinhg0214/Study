#include <stdio.h>

/*
두 집합에 교집합이 존재하면 하나의 집합으로 묶는다 -> disjoint set 
union, find 함수 이용
*/
using namespace std;

int unf[1001];

// 매개변수로 넘어온 v학생의 집합 번호(unf[v])를 리턴
int Find(int v){

    if(v==unf[v]) return v; // 마지막 노드 찾기
    else return Find(unf[v]); // 연결된 노드를 찾아 이동
    
}

int Union(int a, int b){
    a=Find(a);
    b=Find(b);
    if(a!=b) unf[a]=b;
}

int main(){
    int a, b;
    freopen("G:\\Git\\Algorithm-C-\\4.more\\77.is_friend\\input.txt", "rt", stdin);

    int n, m;
    scanf("%d %d", &n, &m);

    // 1차원 배열로 트리 구현. 
    // [i]는 i번째 학생, unf[i]는 i번째와 친구인 학생의 번호가 저장됨
    for(int i=1; i<=n; i++){
        unf[i]=i;   // 먼저 초기화(모두 친구 없음)
    }

    // 친구 정보 읽기
    for(int i=1; i<=m; i++){
        scanf("%d %d", &a, &b);
        Union(a, b);
    }





}