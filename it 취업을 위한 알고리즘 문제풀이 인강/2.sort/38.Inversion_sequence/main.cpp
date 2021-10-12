#include <stdio.h>

int main(){
    freopen("G:\\Git\\Algorithm-C-\\2.sort\\38.Inversion_sequence\\input.txt", "rt", stdin);
    
    int n, is[101], os[101], i, j, pos;

    scanf("%d", &n);

    for(i=1; i<=n; i++){
        scanf("%d", &is[i]);
    }
    /*
     큰 수 부터 1순으로 처리
    각 숫자는 os[n] 에 삽입을 원칙으로함
    대신 자기 앞에 큰수가 몇개 필한지 계산하여 뒤에서 땡겨온 뒤,
    빈자리에 n을 삽입하는 방식으로 접근

    8 앞에 0개 => 8을 마지막에 삽입 os[8] = 8;
    7 앞에 1개 => 8을 앞으로 한칸, 7을 마지막에 삽입
    6 앞에 1개 => os[6]=8, os[7]=6, os[8]=7; 8을 한칸 땡기고 빈자리에 6을 삽입함
    ...

    */
   for(i=n; i>=1; i--){
        pos = i;

        // is[i]번 만큼 앞으로 땡기는 작업
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