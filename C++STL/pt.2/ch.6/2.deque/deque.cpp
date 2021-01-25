/* deque는 vector와 유사하지만, 메모리 블록 할당 정책이 다름.
vector는 하나의 메모리 블록 할당 정책 -> 접근하여 읽고 쓰는데는 빠르지만, 원소가 추가될때 재할당할 때 문제 발생
deque는 여러 메모리 블록을 할당하고, 사용자에게는 하나로 보이게 함. 따로 메모리가 부족할 때마다, 새로 할당하고 이전하는 작업 없이 사용가능

*/

#include <iostream>
#include <deque>

using namespace std;

int main(){
    deque<int> dq;

    for(deque<int>::size_type i =0; i<10; ++i){
        dq.push_back((i+1)*10);
    }

    deque<int>::iterator iter;
    deque<int>::iterator iter2;

    for(iter = dq.begin(); iter != dq.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    iter = dq.begin()+2;

    iter2 = dq.insert(iter, 500); // iter의 위치에 500을 추가. vector와 다르게 메모리 재할당이 일어나지 않고 삽입됨.
    cout << *iter2 << endl;

    for(iter = dq.begin(); iter != dq.end(); ++iter)
        cout << *iter << " ";
    cout << endl;  

    return 0;

}