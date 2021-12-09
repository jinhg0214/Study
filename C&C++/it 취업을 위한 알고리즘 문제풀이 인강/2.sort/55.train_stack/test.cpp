#include <stdio.h>
#include <stack>
#include <vector>

using namespace std;

/*
int 배열 input을 stack에 입력받아
output을 1 2 3 4 5 순서대로 출력
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

        // 삽입 후, 스택 확인
        while(1){
            // 경우 1. 스택이 비어있는경우
            if(crossroad.empty()) break;
            // 경우 2. top에 나갈 차례가 저장된경우
            if(crossroad.top() == j){
                crossroad.pop();
                output.push_back('O');
                j++; // 그 다음번 기차가 나갈 차례
            }
            else break;
        }
    }

    if(!crossroad.empty()) printf("impossible\n");

    else {
        // stack은  index참조가 불가능하므로 vector이용
        for(i=0; i<output.size(); i++){
            printf("%c ", output[i]);
        }
    }







}