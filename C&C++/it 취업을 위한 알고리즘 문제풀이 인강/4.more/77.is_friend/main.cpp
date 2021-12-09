#include <stdio.h>

/*
�� ���տ� �������� �����ϸ� �ϳ��� �������� ���´� -> disjoint set 
union, find �Լ� �̿�
*/
using namespace std;

int unf[1001];

// �Ű������� �Ѿ�� v�л��� ���� ��ȣ(unf[v])�� ����
int Find(int v){

    if(v==unf[v]) return v; // ������ ��� ã��
    else return Find(unf[v]); // ����� ��带 ã�� �̵�
    
}

int Union(int a, int b){
    a=Find(a);
    b=Find(b);
    if(a!=b) unf[a]=b;
}

int main(){
    int a, b;
    freopen("G:\\Git\\Algorithm-C-\\4.more\\77.is_friend\\input.txt", "rt", stdin);

    int n, m;
    scanf("%d %d", &n, &m);

    // 1���� �迭�� Ʈ�� ����. 
    // [i]�� i��° �л�, unf[i]�� i��°�� ģ���� �л��� ��ȣ�� �����
    for(int i=1; i<=n; i++){
        unf[i]=i;   // ���� �ʱ�ȭ(��� ģ�� ����)
    }

    // ģ�� ���� �б�
    for(int i=1; i<=m; i++){
        scanf("%d %d", &a, &b);
        Union(a, b);
    }





}