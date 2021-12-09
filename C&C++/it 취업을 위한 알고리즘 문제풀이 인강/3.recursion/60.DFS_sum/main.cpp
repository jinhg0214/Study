#include <stdio.h>

int n, a[11], total=0;
bool flag=false;

// Level과 원소의 합을 매개변수로 받음
void DFS(int L, int sum){
    if(sum>total/2) return; // 합이 total의 절반을 넘어가면 볼 필요없음
    if(flag==true) return;

    if(L == n+1){ // 종료조건
        if(sum==(total-sum)){
            flag = true;
        }
    }
    else{
        DFS(L+1, sum+a[L]); // 원소의 합을 누적하는 경우
        DFS(L+1, sum); // 원소의 합을 누적하지 않는 경우
    }

}

int main(){
    freopen("G:\\Git\\Algorithm-C-\\3.recursion\\60.DFS_sum\\input.txt", "rt", stdin);

    int i;
    scanf("%d", &n);

    for(i=1; i<=n; i++){
        scanf("%d", &a[i]);
        total += a[i];
    }

    DFS(1, 0);

    if(flag==true) printf("YES");
    else printf("NO");

    return 0;
}