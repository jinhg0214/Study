#include <stdio.h>

using namespace std;

int main(){
    // freopen("G:\\Git\\Algorithm-C-\\1.base\\5.find_age\\input.txt", "rt", stdin);

    char a[20];
    int year, age;

    scanf("%s", &a);

    // age 
    if(a[7]=='1' || a[7] == '2'){
        year = 1900 + ((a[0]-48)*10 + (a[1]-48)); // char to int : ascii - 48
    } else {
        year = 2000 + ((a[0]-48)*10 + (a[1]-48)); // 또는 atoi 사용
    }

    age = 2019 - year +1;
    printf("%d ", age);

    // 성별
    if(a[7]=='1' || a[7] == '3'){
        printf("M\n");
    } else 
        printf("W\n");

    return 0;
}