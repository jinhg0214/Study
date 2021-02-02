#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template<typename T>
void Print(T n){
    cout << n << " ";
}

int main(){
    cout << "==========1.copy()==========" << endl;
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    vector<int> v2(5); // 알고리즘이 덮어쓰기 방식으로 동작하므로, 공간이 없으면 오류발생함!

    vector<int>::iterator iter;

    //구간 [v1.begin(), v1.end())의 모든 원소를 [v2.begin(), v2.begin()+(v1.end() -v1.begin()))의 순차열로 복사
    iter = copy(v1.begin(), v1.end(), v2.begin()); // 10,20,30,40,50 순으로 복사

    cout << "v2 마지막 원소: " << *(iter-1) << endl; // copy 알고리즘은 목적지 끝 반복자를 반환함. 

    cout << "v1 : ";
    for_each(v1.begin(), v1.end(), Print<int>); cout << endl;

    cout << "v2 : ";
    for_each(v2.begin(), v2.end(), Print<int>); cout << endl;

    ///////////////////////////////////////////////////////////////////////////////////////////
    // copy_backward()
    cout << "==========2.copy_backward()==========" << endl;
    v2.resize(10);
    v2.clear();

    // v2의 모든 원소를 0으로 초기화
    iter = v2.begin();
    v2.insert(iter,10,0);
    
    // [v1.begin(), v1.end())의 원소를
    // [iter, v2.end())의 순차열로 마지막 원소부터 복사(50,40,30,20,10)
    iter = copy_backward(v1.begin(), v1.end(), v2.end()); // 목적지 시작 반복자를 반환함

    cout << "v2 첫 원소: " << *iter << endl;

    cout << "v1 : ";
    for_each(v1.begin(), v1.end(), Print<int>); cout << endl;

    cout << "v2 : ";
    for_each(v2.begin(), v2.end(), Print<int>); cout << endl;



    return 0;
}