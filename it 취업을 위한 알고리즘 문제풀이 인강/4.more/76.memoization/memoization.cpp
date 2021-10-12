#include <stdio.h>

/*
5C3 = 4C2(���� ������, ���� ������ 4���̼� ������ 2�ڸ� ����) + 4C3 (���� ������ �ʰ�, 3�ڸ� ����)
...
nCr = (n-1)C(r-1) + (n-1)C(r)
*/
int dy[21][21]={0}; // �޸� ���� ����� �����ϱ�

int DFS(int n, int r){
    if(dy[n][r] > 0) return dy[n][r]; // ����� ������� ������ ��� (�ð� ����)
    if(r==0 || n==r) return 1;
    else 
        // ��� ���� dy�� �����ϸ鼭 ������
        return dy[n][r]=DFS(n-1,r-1)+DFS(n-1,r); 
}

int main(){
    int n, r;
    scanf("%d %d", &n, &r);

    printf("%d\n", DFS(n,r));
    return 0;
}