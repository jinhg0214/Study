#include <stdio.h>


void D(int v){
    
    if(v>7) return;
    else{
        // pre-order ���� ��ȸ
        // printf("%d ",v);
        D(v*2); // ���� �ڽ� ���
        
        // in-order ���� ��ȸ
        // printf("%d ",v);
        D(v*2+1); // ������ �ڽ� ���
        
        // post-order ���� ��ȸ
        // �������Ŀ� ����!
        // printf("%d ",v);
    }    
}

int main(){
    D(1);

    return 0;
}