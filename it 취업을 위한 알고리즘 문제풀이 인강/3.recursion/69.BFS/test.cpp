#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    freopen("G:\\Git\\Algorithm-C-\\3.recursion\\69.BFS\\input.txt", "rt", stdin);

    int start, end, x;
    vector<int> map[10];
    int Q[100], ch[10]={0}, front=-1, back=-1; //üũ �迭�� 0���� �ʱ�ȭ ���� ���� ��� ���� �߻�

    // 6���� ������ �޾� map�� ����
    // ������ ����̹Ƿ� start->End, end->start�� �����Ѵ�
    for(int i=1; i<=6; i++){    
        scanf("%d %d", &start, &end);
        map[start].push_back(end);
        map[end].push_back(start);
    }

    /* map���Ḯ��Ʈ ���
    for(int i=1; i<=6; i++){
        for(int j=0; j<map[i].size(); j++){
            printf("%d ", map[i][j]);
        }
        printf("\n")
    }*/

    // BFS
    // root��� 1 ���� ���� ����
    Q[++back]=1;
    ch[1]=1;

    while(front<back){
        x=Q[++front];
        printf("%d ",x);

        for(int i=0; i<map[x].size(); i++){
            if(ch[ map[x][i] ]==0){
                ch[ map[x][i] ]=1;
                Q[++back]=map[x][i];
            }
        }
    }

    return 0;
}

