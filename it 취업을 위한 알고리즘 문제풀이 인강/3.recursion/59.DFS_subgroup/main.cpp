#include <stdio.h>

int n, chk[11]; // üũ �迭, ������� ���� ������

void DFS(int L){
    // ��������(Level+1)
    if(L == n+1){
        for(int i=1; i<=n; i++){
            if(chk[i]==1){ // üũ �迭�� 1�� ��� ����Ѵ�.
                printf("%d ", i);
            }
        }
        puts("");
    } 
    else {
        chk[L] = 1; // ���� ��尡 �����ϴ� ���
        DFS(L+1);   // ���� �ڽ����� �̵�
        
        chk[L] = 0; // ���� ��尡 �������� �ʴ� ���
        DFS(L+1);   // ������ �ڽ� 
    }

}

int main(){

    scanf("%d", &n);
    
    DFS(1);
    return 0;
}