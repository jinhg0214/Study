#include <stdio.h>

int cache[20];

int main(){
    freopen("G:\\Git\\Algorithm-C-\\2.sort\\37.LRU\\input.txt", "rt", stdin);

    int size, n, i, j, tmp, pos;

    scanf("%d %d",&size ,&n);

    for(i=1; i<n+1; i++){
        scanf("%d", &tmp);

        pos = -1;

        // ĳ�ÿ� tmp���� �����ϴ��� Ȯ��   
        for(j=0; j<size; j++){
            // �����ϸ� hit
            if(cache[j] == tmp){
                pos = j;
            }
        }

        // �������� ������ miss
        if(pos==-1){
            // miss�� ���, �� �տ� tmp�� ���� ��, ��� �ڷ� �̷��
            // ������ ���Ҵ� �״�� ������
            for(j=size-1; j>=1; j--){ // �ڷ� �̷궩 �׻� �ڿ������� ������ �̵��ؾ���
                cache[j] = cache[j-1];
            }
        }
        cache[0] = tmp;

    }


    return 0;
}