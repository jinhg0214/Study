#include <stdio.h>

int main(){
    freopen("G:\\Git\\Algorithm-C-\\2.sort\\36.insert_sort\\input.txt", "rt", stdin);

    int n, a[101], i, j, tmp;

    scanf("%d", &n);

    for(i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    for(i=0;i<n;i++){
        tmp = a[i]; // 삽입할 원소를 tmp에 들고있다가

        for(j = i-1; j>= 0; j--){   // 들어갈 위치를 찾고 삽입
            if(a[j] > tmp){          
                a[j+1] = a[j];  // 뒤로 한칸씩 다 미룸
            }
            else break;
        }

        a[j+1] = tmp;   // 위치에 삽입함
    }

    for(i=0; i<n; i++){
        printf("%d ", a[i]);
    }

    return 0;
}