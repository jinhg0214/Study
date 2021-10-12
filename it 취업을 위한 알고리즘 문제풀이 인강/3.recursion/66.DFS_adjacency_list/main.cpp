#include <stdio.h>
#include <vector>

using namespace std;

// ��������Ʈ�� �̿��� DFSŽ��
// �迭���� �޸�, �ð��� �����!

int ch[30], cnt=0, n;
vector<int> map[30]; 
// ���� '�迭' ����
// index�� ��߷�, ���尪�� �������� �����
// map[n].size()�� ��� ��忡 ����Ǿ��ִ��� Ȯ�� ����


void DFS(int v){

    // �������� �����Ѱ��
    if(v==n){
        cnt++;
    } 
    
    else {
        // v�� ����� ��带 Ȯ��
        for(int i=0; i<map[v].size(); i++){
            
            if(ch[ map[v][i] ]==0){    // ���ʹ� �ε����� ������ ������
                ch[ map[v][i] ] = 1;
                DFS(map[v][i]);
                ch[ map[v][i] ] = 0;
            }
        }
    }

}


int main(){
    freopen("G:\\Git\\Algorithm-C-\\3.recursion\\66.DFS_adjacency_list\\input.txt","rt", stdin);

    int m, i, start, end;

    scanf("%d %d", &n, &m);

    for(int i=1; i<=m; i++){
        scanf("%d %d", &start, &end);
        map[start].push_back(end); 
    }

    ch[1]=1;
    DFS(1);
    printf("%d\n", cnt);

    return 0;
}