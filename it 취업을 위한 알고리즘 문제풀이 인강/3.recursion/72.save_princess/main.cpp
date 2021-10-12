#include <stdio.h>
#include <queue>

/*
ť�� �̿��� ���� ť 
�տ��� pop�� ��, ���ǿ� �������� ���� ���Ҵ� �ڿ� �ٷ� push����
�������� ���� ���Ҹ� ���
*/

using namespace std;

int main(){
    int n, k;
    queue<int> q;

    scanf("%d %d", &n, &k);
    
    for(int i=1; i<=n; i++){
        q.push(i);
    }

    while(!q.empty()){
        for(int i=1; i<k; i++){
            q.push(q.front()); // �� ���� ���� �� �ڿ� Ǫ��
            q.pop();
        }
        // k��°�� pop
        q.pop();
        
        // ������ ���� �ϳ��� �����ִ°�� ���� ���
        if(q.size()==1) printf("%d", q.front());
    }

    return 0;
}