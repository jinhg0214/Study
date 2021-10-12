#include <stdio.h>
#include <stack>
#include <vector>

using namespace std;

int main(){

    stack<int> s;
    int i, j=1, n, m; // j ������ ���� 1���� ���ʷ� n���� �����ؾ���

    scanf("%d", &n);

    vector<char> str;

    for(i=1; i<=n; i++){
        scanf("%d", &m); // ����ϴ� ���� ������ ����

        s.push(m); // �����ο� �����Ƿ� 
        str.push_back('P'); // P�� �߰�����

        // ���� ������ �� 
        while(1){
            if(s.empty()) break; // �������� 1. ������ �������
            if( j==s.top() ){
                s.pop();
                str.push_back('O');
                j++;
            }
            else break;
        }
    }

    if(!s.empty()) printf("impossible\n");
    else {
        for(i=0; i<str.size(); i++){
            printf("%c ",str[i]);
        }
    }

    return 0;
}