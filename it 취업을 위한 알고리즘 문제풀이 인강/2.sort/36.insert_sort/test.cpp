#include <stdio.h>

int main(){
    freopen("G:\\Git\\Algorithm-C-\\2.sort\\36.insert_sort\\input.txt", "rt", stdin);

    int n, a[101], i, j, key;

    scanf("%d", &n);

    for(i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    // �������� : ����Ʈ���� �ּҰ��� ã�� �迭�� �ϼ��ذ��鼭 �̵�
    // �������� : �տ������� ���ʷ� ���ĵ� �迭 �κа� ���Ͽ�, �ڽ��� ��ġ�� ã�� ������
    for(i=0; i<n; i++){
        key = a[i]; 
        // �ڱ� �ڸ� ã��
        for(j=i-1; j>=0; j--){ // �ڿ��� ���� Ȯ���� // �տ������ʹ� �ȵǳ�?
            if(a[j] > key){
                a[j+1] = a[j];
            }
            else break;
        }
        
        a[j+1] = key;  
    }

    for(i=0; i<n; i++){
        printf("%d ", a[i]);
    }

    return 0;
}