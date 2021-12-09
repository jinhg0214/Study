#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
void Print(T n){
    cout << n << " ";
}

int main(){
    //////////////////////////////////////////////////
    // 1. make_heap(b,e)

    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.push_back(60);

    cout << "v : ";

    for_each(v.begin(),v.end(),Print<int>); cout << endl;

    cout << "========== 1. make_heap(b,e) ==========" << endl;
    make_heap(v.begin(),v.end()); // 루트가 가장 큰 최대 힙 생성

    cout << "v[힙 생성] : ";
    for_each(v.begin(),v.end(),Print<int>); cout << endl;

    //////////////////////////////////////////////////
    cout << "========== 2. push_heap(b,e) ==========" << endl;
   
    v.push_back(35);  // 먼저 push_back으로 원소를 추가 후,

    push_heap(v.begin(), v.end()); // 힙 추가 연산을 수행한다. 

    cout << "v[힙 추가] 연산 수행 : ";
    for_each(v.begin(),v.end(),Print<int>); cout << endl;

    //////////////////////////////////////////////////
    cout << "========== 3. pop_heap(b,e) ==========" << endl;
    pop_heap(v.begin(), v.end());

    cout << "v[힙 삭제] 연산 수행 : ";
    for_each(v.begin(),v.end(),Print<int>); cout << endl; // 루트 노드인 60이 가장 뒤로감. 나머지 원소는 힙을 유지함

     //////////////////////////////////////////////////
    cout << "========== 4. sort_heap(b,e) ==========" << endl;
    sort_heap(v.begin(), v.end());

    cout << "v[힙 정렬] 연산 수행 : ";
    for_each(v.begin(),v.end(),Print<int>); cout << endl; // 왜 마지막 원소는 정렬이 안될까?


    return 0;
}