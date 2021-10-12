#include <stdio.h>


void D(int v){
    
    if(v>7) return;
    else{
        // pre-order 전위 순회
        // printf("%d ",v);
        D(v*2); // 왼쪽 자식 노드
        
        // in-order 중위 순회
        // printf("%d ",v);
        D(v*2+1); // 오른쪽 자식 노드
        
        // post-order 후위 순회
        // 병합정렬에 사용됨!
        // printf("%d ",v);
    }    
}

int main(){
    D(1);

    return 0;
}