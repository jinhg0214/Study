#include <iostream>

// bottom up ���
// dy �迭�� �̿�

using namespace std;

int main(){
    
    int n;

    cin >> n;

    int dy[46]; // �ڸ� �� �ִ� ����� ������ �����ϴ� �迭
    dy[1]=1;
    dy[2]=2;

    for(int i=3; i<=n; i++){
        dy[i] = dy[i-1] + dy[i-2];
    }

    cout << dy[n];

    return 0;
}