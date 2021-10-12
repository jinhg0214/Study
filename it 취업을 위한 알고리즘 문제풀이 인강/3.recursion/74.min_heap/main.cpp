#include <stdio.h>
#include <queue>

/*
STL�� �̿��� �ִ� ���� �ݴ�Ǵ� �ּ� ��
STL�� �ִ� ���� �̿��Ͽ� �ּ� ���� ������ 
push�� ��ȣ�� �ٲپ� �����ϰ�,
pop�� ��ȣ�� �ٲپ� ������ �ϼ�
*/

using namespace std;

int main(){
    freopen("G:\\Git\\Algorithm-C-\\3.recursion\\73.max_heap\\input.txt", "rt", stdin);

    int a;

    priority_queue<int> pq; // 

    while(true){
        scanf("%d", &a);
        if(a==-1) break;
        if(a==0){
            if(pq.empty()) printf("-1\n");
            else printf("%d\n", -pq.top()); // �����·� ����
            pq.pop();
        }
        else{
            pq.push(-a); // ���Խ� ������ ���� 
        }
    }

    return 0;
}