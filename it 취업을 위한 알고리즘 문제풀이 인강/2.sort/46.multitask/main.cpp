#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    freopen("G:\\Git\\Algorithm-C-\\2.sort\\46.multitask\\input.txt", "rt", stdin);
    int n, k, pos=0, cnt=0 ,total=0;

    scanf("%d", &n);

    vector<int> task(n+1);


    for(int i=1; i<=n; i++){
        scanf("%d", &task[i]);
        total+=task[i]; // ��ü �ð�
    }

    scanf("%d", &k);

    // ���� ������ ��� �۾��� ����
    if(k>=total){
        printf("-1");   
        return 0;
    }

    while(1){
        pos++;

        if(pos>n) pos=1;

        if(task[pos] == 0){
            continue;
        }

        task[pos]--;
        cnt++; // �� ���

        // ����
        if(cnt == k){
            break;
        }
    }

    // ������ �۾��� �� �������� �����
    while(1){
        pos++;
        if(pos>n) pos=1;

        // �����ִ� �۾� Ž��
        if(task[pos] != 0){
            break;
        }
    }
    
    printf("%d\n", pos);

    return 0;

}