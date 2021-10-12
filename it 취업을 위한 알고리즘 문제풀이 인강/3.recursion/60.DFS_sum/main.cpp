#include <stdio.h>

int n, a[11], total=0;
bool flag=false;

// Level�� ������ ���� �Ű������� ����
void DFS(int L, int sum){
    if(sum>total/2) return; // ���� total�� ������ �Ѿ�� �� �ʿ����
    if(flag==true) return;

    if(L == n+1){ // ��������
        if(sum==(total-sum)){
            flag = true;
        }
    }
    else{
        DFS(L+1, sum+a[L]); // ������ ���� �����ϴ� ���
        DFS(L+1, sum); // ������ ���� �������� �ʴ� ���
    }

}

int main(){
    freopen("G:\\Git\\Algorithm-C-\\3.recursion\\60.DFS_sum\\input.txt", "rt", stdin);

    int i;
    scanf("%d", &n);

    for(i=1; i<=n; i++){
        scanf("%d", &a[i]);
        total += a[i];
    }

    DFS(1, 0);

    if(flag==true) printf("YES");
    else printf("NO");

    return 0;
}