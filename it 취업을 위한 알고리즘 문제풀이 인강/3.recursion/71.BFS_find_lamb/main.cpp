#include <stdio.h>
#include <queue>

/*
                   |5|
       |4|         |6|         |10|
    |3||5||9|   |5||7||11|  |9||11||15|
    ...
    14�� ���ö����� BFS Ž��
    �ߺ��� üũ�ؼ� ������ ������� �ʰ�(�ð����⵵ ���̱� ����)

*/

using namespace std;

int ch[10001]; // �湮�� ��� üũ
int d[3]={-1, +1, +5}; // �̵� ����

int main(){

    int s, e, x, pos;
    scanf("%d %d", &s, &e);

    queue<int> q;

    ch[s]=1; //s���� ����
    q.push(s);

    while(!q.empty()){
        x=q.front();
        q.pop();

        // x���� �̵��� �� �ִ� ��ǥ
        for(int i=0; i<3; i++){
            pos = x+d[i];
            if(pos<=0 || pos>10000){
                continue;
            }

            // ���������� ���
            if(pos == e){
                printf("%d\n",ch[x]);
                return 0;
            }

            // ���� ������ �ƴϰ�, �ѹ��� �湮���� ���� ���
            if(ch[pos]==0){
                ch[pos]=ch[x]+1; // ������ �ּ� Ƚ���� ���. ���� ��ǥ�� �ּ�Ƚ�� +1
                q.push(pos); 
            }
        }
    }

    return 0;
}