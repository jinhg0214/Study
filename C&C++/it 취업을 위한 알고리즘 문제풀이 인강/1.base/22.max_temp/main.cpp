#include <stdio.h>
#include <vector>

int main(){
    freopen("G:\\Git\\Algorithm-C-\\1.base\\22.max_temp\\input.txt", "rt", stdin);

    int n, k, sum=0, max;

    // 입력 받기
    scanf("%d %d", &n, &k);
    
    std::vector<int> a(n);

    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    /*
    // 계산(2중 for문 time over)
    for(int i=0; i<n; i++){
        tmp = 0;
        for(int j=i; j<i+k; j++){
            tmp += temp[j];
        }
        if(tmp > max_temp){
            max_temp = tmp;
        }
    }*/

    // 첫 구간의 합
    for(int i=0; i<k; i++){
        sum += a[i];
    }
    max = sum;

    // sum + a[i] - a[i-k]를 이용
    // 한칸씩 전진
    for(int i=k; i<n; i++){
        sum = sum+(a[i] - a[i-k]);
        if(sum > max) max = sum;
    }

    // 출력
    printf("%d\n", max);

    return 0;
}