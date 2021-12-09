#include <stdio.h>
#include <queue>

/*
STL을 이용한 최대 힙과 반대되는 최소 힙
STL의 최대 힙을 이용하여 최소 힙을 구현함 
push시 부호를 바꾸어 저장하고,
pop시 부호를 바꾸어 꺼내면 완성
*/

using namespace std;

int main(){
    freopen("G:\\Git\\Algorithm-C-\\3.recursion\\73.max_heap\\input.txt", "rt", stdin);

    int a;

    priority_queue<int> pq; // 

    while(true){
        scanf("%d", &a);
        if(a==-1) break;
        if(a==0){
            if(pq.empty()) printf("-1\n");
            else printf("%d\n", -pq.top()); // 원상태로 복귀
            pq.pop();
        }
        else{
            pq.push(-a); // 삽입시 음수로 저장 
        }
    }

    return 0;
}