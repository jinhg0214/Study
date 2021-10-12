#include <stdio.h>
#include <queue>

/*
큐를 이용해 원형 큐 
앞에서 pop한 뒤, 조건에 충족하지 않은 원소는 뒤에 바로 push해줌
마지막에 남은 원소를 출력
*/

using namespace std;

int main(){
    int n, k;
    queue<int> q;

    scanf("%d %d", &n, &k);
    
    for(int i=1; i<=n; i++){
        q.push(i);
    }

    while(!q.empty()){
        for(int i=1; i<k; i++){
            q.push(q.front()); // 맨 앞의 값을 맨 뒤에 푸쉬
            q.pop();
        }
        // k번째는 pop
        q.pop();
        
        // 마지막 원소 하나만 남아있는경우 정답 출력
        if(q.size()==1) printf("%d", q.front());
    }

    return 0;
}