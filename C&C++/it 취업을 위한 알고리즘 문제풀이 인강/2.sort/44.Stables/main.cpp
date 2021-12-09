#include <stdio.h>
#include <algorithm>

using namespace std;

int n;

// x[] �迭�� len�� �Է¹޾�
// �ִ� �� �� �ִ� ���� ���� �����ϴ� �Լ�
// ex) 1~9�� 3�̸�-> 1, 4, 7 = rtn 3 
int Count(int len, int x[]){
    int i, cnt=1, pos=x[1];

    for(i=2; i<=n; i++){
        if(x[i]-pos>= len){
            cnt++; 
            pos=x[i];
        }
    }
    return cnt;
}

int main(){
    freopen("G:\\Git\\Algorithm-C-\\2.sort\\44.Stables\\input.txt", "rt", stdin);

    int c, i, lt=1, rt, mid, res;

    scanf("%d %d", &n, &c);

    // 1���� ���� �迭 ����
    int *x = new int[n+1];

    for(i=1;i<=n; i++){
        scanf("%d", &x[i]);
    }

    // ����
    sort(x+1, x+n+1);

    rt=x[n]; //rt�� ���� ����Ŵ 

    // �̺� �˻� 
    while(lt <= rt){ // lt�� rt�� ������ ����
        mid = (lt+rt)/2;    // �߰� ��

        if(Count(mid, x)>= c){  // mix~x ���̿� ���� ���� ���� c���� ū��? = c ������ mid~x�� �� �� �ִ°�
            res = mid;
            lt = mid+1;
        }
        else rt= mid-1; // �����ٸ� 
    }

    printf("%d\n", res);
    delete[] x;

    return 0;
}