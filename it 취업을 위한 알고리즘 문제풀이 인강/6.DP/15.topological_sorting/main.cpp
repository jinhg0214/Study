/*
���� ������ �����ϴ� �迭
        1   2   3   4   5   6
degree  0   1   2   2   1   0     

0���� ������� ť�� ���� 
ť���� �����鼭, �� ���� ����� ���������� 1 ���ҽ�����
ex) 6�� �����鼭 2�� 1 ���ҽ�Ŵ-> ���� ť�� 2�� ���Ե�

queue 1 6 2 5 4 3   

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    freopen("G:\\Git\\Algorithm-C-\\6.DP\\15.topological_sorting\\input.txt", "rt", stdin);

    int n, m, a, b, score;

    cin >> n >> m;

    vector<vector<int> > graph(n+1, vector<int>(n+1, 0));
    vector<int> degree(n+1);
    queue<int> Q;

    for(int i=0; i<m; i++){
        cin >> a >> b;
        graph[a][b]=1; // �ܹ���
        degree[b]++; // �������� 1 ����
    }

    // ���������� 0�� ��� ���� ó��
    for(int i=1; i<=n; i++){
        if(degree[i]==0) Q.push(i); 
    }

    while(!Q.empty()){
        int now = Q.front();
        Q.pop();

        cout << now << " ";

        for(int i=1; i<=n; i++){
            if(graph[now][i] == 1){  //i�� ����� ����� �������� 1 ����
                degree[i]--;
                if(degree[i] == 0) Q.push(i); //i�� 0�� �Ǹ� ť�� ����
            }
        }
    }

    return 0;
}