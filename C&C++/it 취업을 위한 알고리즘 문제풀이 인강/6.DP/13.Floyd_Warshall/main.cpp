/*
�÷��̵� ���� �˰���.
��� ���������� ��� �ٸ� �������α����� �ִܰŸ��� ���ϴ� �˰���

d[i][j] : i��� -> j���� ���µ� ��� �ּ� ����� �����ϴ� 2���� �迭
 
dis 1   2   3   4   5
1   0   6   3   M   M
2   M   0   M   1   13
3   M   2   0   5   M
4   M   3   M   0   7
5   M   M   M   M   0

1. ���� ����� �ʱ�ȭ(�ѹ��� ���� �� �� �ִ°�) 
2. �������� ���� ���� INF �� �ʱ�ȭ
3. (dis[i][j], dis[i][k] + dis[k][j]) ��(k��忡 �湮�ϴ� ���� ��)

K=3, dis[5][4] = dis[5][3]  + dis[3][4] + dis[4][5]
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    freopen("G:\\Git\\Algorithm-C-\\6.DP\\13.Floyd_Warshall\\input.txt", "rt", stdin);

    int n, m, a,b,c;

    cin >> n >> m;

    vector<vector<int> > dis(n+1, vector<int>(n+1, 5000)); // INF�� �ʱ�ȭ�� 2���� ����

    for(int i=1; i<=n; i++) dis[i][i] = 0; // �ڱ� �ڽŰ��� �Ÿ��� 0

    // �ѹ��� ���� �� �� �ִ� ���� �ʱ�ȭ
    for(int i=1; i<=m; i++){
        cin >> a >> b >> c;
        dis[a][b] = c; 
    }

    // DP
    for(int k=1; k<=n; k++){ 
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){ // i -> k -> j
                if(dis[i][j] > dis[i][k] + dis[k][j]){
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(dis[i][j]== 5000){
                cout << "M ";
            }
            else cout << dis[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}