#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){

    stack<int, vector<int>> st; // vector �����̳ʸ� �̿��� stack �����̳� ����?? stack �����̳� �������� �����̳�??
    // vector �����̳ʸ� ������ ������ �����ϴ� stack �����̳�
    st.push(10);
    st.push(20);
    st.push(30);

    while(!st.empty()){
        cout << st.top() << endl;
        st.pop(); 
    }
    cout<< "stack�� ������ ����!";
    
    return 0;
}