#include <stdio.h>
#include <queue>

/*
STL의 max_heap이용
max heap은 부모 노드가 자식 노드보다 항상 큼
루트에 항상 최대값이 들어있음

pq.top() 루트값 참조



*/

using namespace std;

int main(){
    freopen("G:\\Git\\Algorithm-C-\\3.recursion\\73.max_heap\\input.txt", "rt", stdin);

    int a;

    priority_queue<int> pq;

    while(true){
        scanf("%d", &a);
        if(a==-1) break;
        if(a==0){
            if(pq.empty()) printf("-1\n");
            else printf("%d\n", pq.top());
            pq.pop();
        }
        else{
            pq.push(a); // 알아서 노드의 위치를 찾아 삽입됨
        }
    }

    return 0;
}