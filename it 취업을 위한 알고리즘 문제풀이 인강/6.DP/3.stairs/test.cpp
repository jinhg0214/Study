#include <iostream>

using namespace std;

// n단계의 계단을 오르는 가지 수 
// 1칸 또는 최대 2칸까지 가능

int dy[50];

int main(){
    int n; 

    cin >> n;

    dy[1]=1;
    dy[2]=2;\

    for(int i=3; i<=n; i++){
        dy[i] = dy[i-2] + dy[i-1];
    }

    cout << dy[n];

    return 0;
}