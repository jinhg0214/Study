#include <iostream>

// ¡�˴ٸ�
// 5�� ����� ¡�˴ٸ��� �������� ��� �� ���ٰ� �� ��� 

using namespace std;

int dy[50];

int DFS(int n){
    
    if(n%5 == 0) return dy[n] = 0;
    if(dy[n] != 0) return dy[n]; // Memoization
    else if(n == 1 || n == 2) return n;
    else return dy[n] = DFS(n-1) + DFS(n-2);
}

int main(){

    int n;

    cin >> n;

    cout << DFS(n);

    return 0;
}