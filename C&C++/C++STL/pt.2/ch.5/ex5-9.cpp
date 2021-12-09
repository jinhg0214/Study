#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){

    stack<int, vector<int>> st; // vector 컨테이너를 이용한 stack 컨테이너 생성?? stack 컨테이너 어탭터의 컨테이너??
    // vector 컨테이너를 적용한 정수를 저장하는 stack 컨테이너
    st.push(10);
    st.push(20);
    st.push(30);

    while(!st.empty()){
        cout << st.top() << endl;
        st.pop(); 
    }
    cout<< "stack에 데이터 없음!";
    
    return 0;
}