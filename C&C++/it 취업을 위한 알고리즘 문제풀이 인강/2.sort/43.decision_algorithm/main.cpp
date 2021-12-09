#include <stdio.h>
#include <algorithm>

/*
            1~45
    1~22           
1~11x   12~22o    
    12~16x   16~22o 
                ...

*/     

using namespace std;

// DVD�뷮 ���� ������ Ȯ���ϴ� �Լ�
int Count(int s){
    int i, cnt=1, sum=0;
    for(i=1; i<n; i++){
        if(sum+a[i] > s){ // ��ȭ�� �� �ִ°�?
            cnt++;  // �Ұ��� �� ��� ���ο� dvd�� �߰���
            sum=a[i];
        }    
        else 
            sum += a[i];
    }
    return cnt;
}

int a[1001], n;

int main(){

    freopen("G:\\Git\\Algorithm-C-\\2.sort\\43.decision_algorithm\\input.txt", "rt", stdin);

    int m, i, lt=1, rt=0, mid, res;

    scanf("%d %d", &n, &m);

    for(i=1; i<=n; i++){
        scanf("%d", &a[i]);
        rt = rt+a[i];   // �ִ� ��� �ð� 
    }

    while(lt <= rt){
        mid = (lt+rt)/2;
        if(Count(mid)<=m){
            res = mid;
            rt=mid-1;
        } 
        else{
            lt = mid+1;
        }
    }
    printf("%d\n", res);


    return 0;

}