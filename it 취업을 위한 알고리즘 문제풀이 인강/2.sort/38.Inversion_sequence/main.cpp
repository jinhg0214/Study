#include <stdio.h>

int main(){
    freopen("G:\\Git\\Algorithm-C-\\2.sort\\38.Inversion_sequence\\input.txt", "rt", stdin);
    
    int n, is[101], os[101], i, j, pos;

    scanf("%d", &n);

    for(i=1; i<=n; i++){
        scanf("%d", &is[i]);
    }
    /*
     ū �� ���� 1������ ó��
    �� ���ڴ� os[n] �� ������ ��Ģ������
    ��� �ڱ� �տ� ū���� � ������ ����Ͽ� �ڿ��� ���ܿ� ��,
    ���ڸ��� n�� �����ϴ� ������� ����

    8 �տ� 0�� => 8�� �������� ���� os[8] = 8;
    7 �տ� 1�� => 8�� ������ ��ĭ, 7�� �������� ����
    6 �տ� 1�� => os[6]=8, os[7]=6, os[8]=7; 8�� ��ĭ ����� ���ڸ��� 6�� ������
    ...

    */
   for(i=n; i>=1; i--){
        pos = i;

        // is[i]�� ��ŭ ������ ����� �۾�
        for(j=1; j<=is[i]; j++){
            os[pos] = os[pos+1];
            pos++;
        }

        os[pos] = i;
    }
    for(i=1; i<=n; i++){
        printf("%d ", os[i]);
    }
  
    return 0;
}