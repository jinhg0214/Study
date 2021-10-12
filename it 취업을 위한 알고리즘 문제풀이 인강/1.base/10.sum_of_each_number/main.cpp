#include <stdio.h>

// 각 자리의 자연수를 합을 구하는 함수
int digit_sum(int x){
    int tmp, sum=0;
    
    while(x > 0){
        tmp = x%10;
        sum += tmp;
        x = x/10;
    };

    return sum;
}

int main(){
    freopen("G:\\Git\\Algorithm-C-\\1.base\\10.sum_of_each_number\\input.txt", "rt", stdin);

    int n, num, sum, max=-2147000000, res;

    scanf("%d", &n);

    // 각 숫자를 입력받아 각 자리의 자연수 합이 최대인지 확인
    for(int i=0; i<n; i++){
        scanf("%d", &num);
        sum = digit_sum(num);

        if(sum > max){
            max = sum;
            res = num;
        }
        // 자리수의 최대 값이 같은 경우?
        else if(sum == max){
            if(num > res){ // 숫자가 큰 것을 취함
                res = num;
            }
        }
    }
    printf("%d", res);

    return 0;

}
