#include <stdio.h>

int main(){
    freopen("G:\\Git\\Algorithm-C-\\2.sort\\36.insert_sort\\input.txt", "rt", stdin);

    int n, a[101], i, j, key;

    scanf("%d", &n);

    for(i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    // 선택정렬 : 리스트에서 최소값을 찾아 배열을 완성해가면서 이동
    // 삽입정렬 : 앞에서부터 차례로 정렬된 배열 부분과 비교하여, 자신의 위치를 찾아 삽입함
    for(i=0; i<n; i++){
        key = a[i]; 
        // 자기 자리 찾기
        for(j=i-1; j>=0; j--){ // 뒤에서 부터 확인함 // 앞에서부터는 안되나?
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