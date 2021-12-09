#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    freopen("G:\\Git\\Algorithm-C-\\2.sort\\42.binary_search\\input.txt", "rt", stdin);

    int n, m;

    scanf("%d %d", &n, &m);

    vector<int> a(n);

    for(int i =0; i<n; i++){
        scanf("%d", &a[i]);
    }

    // a�� ����
    sort(a.begin(), a.end());

    // �߰����� ��� ��
    int lt=0, rt=n, mid, res;   // lt�� 0����, rt�� n���� �ʱ�ȭ
    
    while(1){
        mid = (lt+rt)/2;
        if(a[mid] == m){
            res = mid+1; // n+1��° �ڸ��� �����
            break;
        } else if (a[mid] > m){
            rt = mid-1;
        } else {
            lt = mid+1;
        }
    }

    printf("%d", res);

}