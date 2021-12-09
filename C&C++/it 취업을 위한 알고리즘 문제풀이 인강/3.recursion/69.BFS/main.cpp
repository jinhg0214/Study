#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int Q[100], front=-1, back=-1, ch[10];
vector<int> map[10];

int main(){
    freopen("G:\\Git\\Algorithm-C-\\3.recursion\\69.BFS\\input.txt", "rt", stdin);

    int i, a, b, x;

    for(i=1; i<=6; i++){
        scanf("%d %d", &a, &b);
        // ������ �����Ƿ� a->b, b->a �� �߰�
        map[a].push_back(b); 
        map[b].push_back(a);
    }
    
    //ť�� �̿��Ͽ� BFSŽ��
    Q[++back]=1; // root
    ch[1]=1;

    while(front<back){
        x=Q[++front];
        printf("%d ", x);

        // x�� ����� ��带 ť�� ����
        for(i=0; i<map[x].size(); i++){
            if(ch[ map[x][i]] == 0){
                ch[map[x][i]]=1;    // �湮 ����
                Q[++back]=map[x][i];
            }
        }
    }

    return 0;
}