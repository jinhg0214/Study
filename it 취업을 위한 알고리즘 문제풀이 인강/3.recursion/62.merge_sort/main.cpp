#include <stdio.h>

int data[10], tmp[10];

// ���� ���� �Լ�
// ���� ���� 1, n�� ����
void divide(int lt, int rt){

    int mid;
    int p1, p2, p3;

    
    if(lt < rt){
        // ����
        mid = (lt+rt)/2; // �߰���
        divide(lt, mid);    // �ڽĳ��1 : lt~mid ����
        divide(mid+1, rt);  // �ڽĳ��2 : mid+1~rt ����

        // ����, ����
        // d(1,1), d(2,2)�� ������ �� ���
        p1=lt;
        p2=mid+1;
        p3=lt;

        while(p1 <= mid && p2 <= rt){
            if(data[p1] < data[p2]){
                tmp[p3]=data[p1];
                p1++;
                p3++;
            }  
            else{
                tmp[p3] = data[p2];
                p2++;
                p3++;
            }
        } 
        while(p1 <= mid){
            tmp[p3] = data[p1];
            p1++;
            p3++;
        }
        while(p2 <= rt){
            tmp[p3] = data[p2];
            p2++;
            p3++;
        }

        // ���� �迭�� tmp�� ����
        for(int i=lt; i<=rt; i++){
            data[i]=tmp[i];
        }
    }
}

int main(){

    freopen("G:\\Git\\Algorithm-C-\\3.recursion\\62.merge_sort\\input.txt","rt", stdin);

    int n, i;

    scanf("%d", &n);

    for(i=1; i<=n; i++){
        scanf("%d", &data[i]);
    }

    divide(1,n);

    for(i=1; i<=n; i++){
        printf("%d ", data[i]);
    }

}