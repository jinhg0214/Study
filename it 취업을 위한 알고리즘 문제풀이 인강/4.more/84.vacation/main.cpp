#include <stdio.h>

int n, t[16], p[16], res = -2147000000;

void DFS(int L, int sum){

    if(L==n+1){ // ������ ���� ������ ��� ���� res ���� ��
        if(sum > res) res = sum;
    } 
    
    else {
        if(L+t[L] <= n+1){ // ��¥�� �Ѿ�� �ʵ��� 
            DFS(L+t[L], sum + p[L]); // �ϰ� ��������
        }
        DFS(L+1, sum); // ���ϰ� �������� 

    }
}

int main(){
    freopen("G:\\Git\\Algorithm-C-\\4.more\\84.vacation\\input.txt", "rt", stdin);

    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        scanf("%d %d", &t[i], &p[i]);
    }

    DFS(1, 0);

    printf("%d", res);
    return 0;

}