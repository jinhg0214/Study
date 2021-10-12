#include <stdio.h>
#include <algorithm>

using namespace std;

int n;

// x[] 배열과 len을 입력받아
// 최대 들어갈 수 있는 말의 수를 리턴하는 함수
// ex) 1~9에 3이면-> 1, 4, 7 = rtn 3 
int Count(int len, int x[]){
    int i, cnt=1, pos=x[1];

    for(i=2; i<=n; i++){
        if(x[i]-pos>= len){
            cnt++; 
            pos=x[i];
        }
    }
    return cnt;
}

int main(){
    freopen("G:\\Git\\Algorithm-C-\\2.sort\\44.Stables\\input.txt", "rt", stdin);

    int c, i, lt=1, rt, mid, res;

    scanf("%d %d", &n, &c);

    // 1차원 동적 배열 생성
    int *x = new int[n+1];

    for(i=1;i<=n; i++){
        scanf("%d", &x[i]);
    }

    // 정렬
    sort(x+1, x+n+1);

    rt=x[n]; //rt는 끝을 가리킴 

    // 이분 검색 
    while(lt <= rt){ // lt가 rt를 넘으면 종료
        mid = (lt+rt)/2;    // 중간 값

        if(Count(mid, x)>= c){  // mix~x 사이에 들어가는 말의 수가 c보다 큰가? = c 마리가 mid~x에 들어갈 수 있는가
            res = mid;
            lt = mid+1;
        }
        else rt= mid-1; // 못들어간다면 
    }

    printf("%d\n", res);
    delete[] x;

    return 0;
}