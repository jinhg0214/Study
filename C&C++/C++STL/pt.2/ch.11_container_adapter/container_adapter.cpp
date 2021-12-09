#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <deque>

using namespace std;

int main(){
    cout << "========== 1. stack ==========" << endl;

    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    
    while(!st.empty()){
        cout << st.top() << endl;
        st.pop();
    }

    cout << "========== 2. queue ==========" << endl;
    queue<int, list<int>> q; // 리스트를 사용하는 queue 생성

    q.push(10);
    q.push(20);
    q.push(30);

    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }

    cout << "========== 3. priority_queue ==========" << endl;

    priority_queue<int> pq1; // 기본 컨테이너 vector<int>, 기본 정렬 less
    pq1.push(40);
    pq1.push(20);
    pq1.push(30);
    pq1.push(50);
    pq1.push(10);

    cout << "priority_queue[less]:" << endl;
    
    while(!pq1.empty()){
        cout << pq1.top() << endl;
        pq1.pop();
    }

    cout << "==========" << endl;

    priority_queue<int, deque<int>, greater<int>> pq2;
    pq2.push(40);
    pq2.push(20);
    pq2.push(30);
    pq2.push(50);
    pq2.push(10);

    cout << "priority_queue[greater]:" << endl;

    while(!pq2.empty()){
        cout << pq2.top() << endl;
        pq2.pop();
    }

    return 0;
}