#include <stdio.h>

using namespace std;

int unf[1001]; // 번호와, 그 번호가 연결된 포인터를 저장하는 배열

// v가 어느 집합에 속해있는지 리턴하는 함수
int Find(int v){
    if(v==unf[v]) return v;
    else return unf[v]=Find(unf[v]); // 메모이제이션
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a!=b) unf[a]=b;
}

int main(){
    freopen("G:\\Git\\Algorithm-C-\\4.more\\77.is_friend\\input.txt", "rt", stdin);
    
    int n, m, a, b;

    scanf("%d %d", &n, &m);

    for(int i=1; i<=n; i++){
        unf[i]=i; // 초기화. 자기 자신에 연결시킴(연결되지 않은 상태로 초기화)
    }

    for(int i=1; i<=m; i++){
        scanf("%d %d", &a, &b);
        Union(a, b);
    }

    scanf("%d %d", &a, &b);
    a = Find(a);
    b = Find(b);

    if(a==b) printf("YES\n");
    else printf("NO\n");

    return 0;
}