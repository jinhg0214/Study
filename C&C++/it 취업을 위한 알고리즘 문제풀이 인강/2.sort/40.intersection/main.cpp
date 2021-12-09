#include <stdio.h>
#include <vector>
#include <algorithm>

    // 1. �� ������ �����ؼ� a, b�迭�� �ִ´�.
    // 2. ������ p1, p2, p3�� a,b,c ������
    // 3. a[p1] == b[p2]�� ��� c[p3]�� ������ c�� ����Ѵ�


using namespace std;

int main(){
    freopen("G:\\Git\\Algorithm-C-\\2.sort\\40.intersection\\input.txt", "rt", stdin);

    int n, m, i, j, p1=0, p2=0, p3=0;

    // �Է� �޴� �κ�
    // a, b �迭�� ����
    scanf("%d", &n);

    vector<int> a(n);
    for(i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    sort(a.begin(), a.end());

    scanf("%d", &m);

    vector<int> b(m), c(n+m);

    for(i=0; i<m; i++){
        scanf("%d", &b[i]);
    }

    sort(b.begin(), b.end());

    // �� �� ���� ���Ҹ� c�� ����
    while(p1<n && p2<m){
        if(a[p1] == b[p2]){
            c[p3++] = a[p1++];
            p2++;
        } else if(a[p1] < b[p2]){
            p1++;
        } else 
            p2++;
    }

    for(i=0; i<p3; i++){
        printf("%d ", c[i]);
    }

    return 0;

}