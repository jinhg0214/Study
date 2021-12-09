#include <stdio.h>

using namespace std;

int unf[1001]; // ��ȣ��, �� ��ȣ�� ����� �����͸� �����ϴ� �迭

// v�� ��� ���տ� �����ִ��� �����ϴ� �Լ�
int Find(int v){
    if(v==unf[v]) return v;
    else return unf[v]=Find(unf[v]); // �޸������̼�
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
        unf[i]=i; // �ʱ�ȭ. �ڱ� �ڽſ� �����Ŵ(������� ���� ���·� �ʱ�ȭ)
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