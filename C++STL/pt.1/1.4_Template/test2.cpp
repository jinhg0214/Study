#include <iostream>

using namespace std;


template<typename T>
class Stack{
    T buf[100];
    int top;
    // int capacity;
public:
    /*explicit Stack(int cap = 100):top(0), capacity(cap){ // 최대 크기 100인 스택 생성
        buf = new T[capacity];
    }

    ~Stack(){
        delete [] buf;
    }
    */
    Stack():top(0) { }

    void Push(const T& item){
        buf[top++] = item;
    }

    const T& Pop(){
       return buf[--top];
    }
    
    bool Empty() const{
        return top <= 0;
    }
};


int main(){
    Stack<int> st;

    st.Push(10);
    st.Push(20);
    st.Push(30);

    if(!st.Empty()){
        cout << st.Pop() << endl; // 30
    }
    if(!st.Empty()){
        cout << st.Pop() << endl; // 20
    }    
    if(!st.Empty()){
        cout << st.Pop() << endl; // 10
    }

    return 0;
}