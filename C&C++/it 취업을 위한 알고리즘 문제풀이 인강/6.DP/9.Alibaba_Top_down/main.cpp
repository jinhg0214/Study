#include <iostream>
#include <algorithm>

/* 
D(2,2) : (0,0)���� �����ؼ� (2,2)�� �����ϴµ� ��� �ּ� ���
|      \
D(2,1)   D(1,2)
|      \
D(2,0) D(1,1) <- �� ���� ������ ȣ��Ǵ°��� Memoization 
|
D(1,0) �����ڸ� ���޽� ���� ȣ�� ��� ����

*/

using namespace std;

int arr[21][21], dy[21][21];

int DFS(int x, int y){

    // memoization
    if(dy[x][y] != 0) return dy[x][y];

    // �ٴڿ� ����
    if(x==0 && y==0) return arr[0][0];
    else{
        // �����ڸ��� ���
        if(y==0) return dy[x][y] = DFS(x-1, y) + arr[x][y];
        else if (x==0) return dy[x][y] = DFS(x, y-1) + arr[x][y];
        // �� ��
        else 
            return dy[x][y] = min(DFS(x-1,y) ,DFS(x, y-1)) + arr[x][y];
    }


}

int main(){
    freopen("G:\\Git\\Algorithm-C-\\6.DP\\8.Alibaba_Bottom_up\\input.txt", "rt", stdin);

    int n;

    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    cout << DFS(n-1, n-1) << endl;

    return 0;
}