#include <iostream>

// bottom up 방법
// dy 배열을 이용

using namespace std;

int main(){
    
    int n;

    cin >> n;

    int dy[46]; // 자를 수 있는 방법의 개수를 저장하는 배열
    dy[1]=1;
    dy[2]=2;

    for(int i=3; i<=n; i++){
        dy[i] = dy[i-1] + dy[i-2];
    }

    cout << dy[n];

    return 0;
}