#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
void Print(T n){
    cout << n << " ";
}

// p, p+1의 차이가 10 이하라면 참
bool Pred(int left, int right){
    return abs(right-left) < 10;
}

int main(){
    //////////////////////////////////////////////////
    // unique(b,e,f) : 구간 [b,e)의 반복자 p에서, f(*p)가 참인 인접한 원소를 논리적으로 제거함.
    cout << "========== 1. unique(b,e) ==========" << endl;

    vector<int> v;
    v.push_back(10);
    v.push_back(11);
    v.push_back(30);
    v.push_back(32);
    v.push_back(40);
    v.push_back(50);

    for_each(v.begin(), v.end(), Print<int>); cout << endl;

    vector<int>::iterator iter_end;
    iter_end = unique(v.begin(), v.end(), Pred);

    for_each(v.begin(), v.end(), Print<int>); cout << endl; // 10 30 40 50 (40 50)<- 논리적 제거 후 남은 데이터. 마찬가지로 erase() 필요

    for(vector<int>::iterator iter = v.begin(); iter != iter_end; iter++){
        cout << *iter << " ";
    } cout << endl;

    // unique_copy는 인접한 중복 원소를 제거하여, 목적지 순차열로 복사함. 나머지는 unique()와 같음

    return 0;

}