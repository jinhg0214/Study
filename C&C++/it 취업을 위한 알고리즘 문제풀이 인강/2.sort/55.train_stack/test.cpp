#include <stdio.h>
#include <stack>
#include <vector>

using namespace std;

/*
int �迭 input�� stack�� �Է¹޾�
output�� 1 2 3 4 5 ������� ���
*/

int main(){
    int n, start[31], i, j=1;
    stack<int> crossroad;
    vector<char> output;    

    scanf("%d", &n);

    for(i=0; i<n; i++){
        scanf("%d", &start[i]); 

        crossroad.push(start[i]);
        output.push_back('P');

        // ���� ��, ���� Ȯ��
        while(1){
            // ��� 1. ������ ����ִ°��
            if(crossroad.empty()) break;
            // ��� 2. top�� ���� ���ʰ� ����Ȱ��
            if(crossroad.top() == j){
                crossroad.pop();
                output.push_back('O');
                j++; // �� ������ ������ ���� ����
            }
            else break;
        }
    }

    if(!crossroad.empty()) printf("impossible\n");

    else {
        // stack��  index������ �Ұ����ϹǷ� vector�̿�
        for(i=0; i<output.size(); i++){
            printf("%c ", output[i]);
        }
    }







}