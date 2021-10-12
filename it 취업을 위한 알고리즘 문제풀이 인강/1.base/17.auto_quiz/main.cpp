#include <stdio.h>

int main(){
    // freopen("G:\\Git\\Algorithm-C-\\1.base\\17.auto_quiz\\input.txt", "rt", stdin);
    int nums_of_students, n, ans, sum=0;

    // 반 학생수 
    scanf("%d", &nums_of_students);

    for(int i=0; i<nums_of_students; i++){
        // 학생에게 부여된 번호
        scanf("%d %d", &n, &sum);
        ans = (n*(n+1))/2;
        if(sum == ans) printf("YES\n");
        else printf("NO\n");
    }
    
    return 0;
}