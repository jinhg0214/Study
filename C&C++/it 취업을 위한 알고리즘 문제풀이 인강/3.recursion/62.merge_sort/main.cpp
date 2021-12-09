#include <stdio.h>

int data[10], tmp[10];

// 분할 정렬 함수
// 정렬 범위 1, n을 받음
void divide(int lt, int rt){

    int mid;
    int p1, p2, p3;

    
    if(lt < rt){
        // 분할
        mid = (lt+rt)/2; // 중간값
        divide(lt, mid);    // 자식노드1 : lt~mid 까지
        divide(mid+1, rt);  // 자식노드2 : mid+1~rt 까지

        // 정렬, 병합
        // d(1,1), d(2,2)가 끝나고 온 경우
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

        // 원래 배열에 tmp를 복사
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