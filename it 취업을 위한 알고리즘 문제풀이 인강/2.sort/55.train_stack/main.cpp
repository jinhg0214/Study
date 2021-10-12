#include <stdio.h>
#include <stack>
#include <vector>

using namespace std;

int main(){

    stack<int> s;
    int i, j=1, n, m; // j 기차의 순서 1부터 차례로 n까지 도착해야함

    scanf("%d", &n);

    vector<char> str;

    for(i=1; i<=n; i++){
        scanf("%d", &m); // 출발하는 기차 순으로 읽음

        s.push(m); // 교차로에 들어갔으므로 
        str.push_back('P'); // P를 추가해줌

        // 도착 순서와 비교 
        while(1){
            if(s.empty()) break; // 종료조건 1. 스택이 비어있음
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