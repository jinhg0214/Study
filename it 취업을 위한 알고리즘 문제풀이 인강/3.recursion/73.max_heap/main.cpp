#include <stdio.h>
#include <queue>

/*
STL�� max_heap�̿�
max heap�� �θ� ��尡 �ڽ� ��庸�� �׻� ŭ
��Ʈ�� �׻� �ִ밪�� �������

pq.top() ��Ʈ�� ����



*/

using namespace std;

int main(){
    freopen("G:\\Git\\Algorithm-C-\\3.recursion\\73.max_heap\\input.txt", "rt", stdin);

    int a;

    priority_queue<int> pq;

    while(true){
        scanf("%d", &a);
        if(a==-1) break;
        if(a==0){
            if(pq.empty()) printf("-1\n");
            else printf("%d\n", pq.top());
            pq.pop();
        }
        else{
            pq.push(a); // �˾Ƽ� ����� ��ġ�� ã�� ���Ե�
        }
    }

    return 0;
}