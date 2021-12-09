#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
void Print(T n){
    cout << n << " ";
}

// *(p+1)이 *p 보다 3보다 크면 참을 반환
// 두 원소의 차이가 3이하라면, 같은 원소로 취급함
bool Pred(int left, int right){
    return 3 < right - left;
}

int main(){
    //////////////////////////////////////////////////
    cout << "========== 1. binary_search(b,e,x,f) ==========" << endl;
    vector<int> v;

    v.push_back(40);
    v.push_back(46);
    v.push_back(12);
    v.push_back(80);
    v.push_back(10);
    v.push_back(47);
    v.push_back(30);
    v.push_back(55);
    v.push_back(90);
    v.push_back(53);

    cout << "[v: 원본] : ";
    for_each(v.begin(), v.end(), Print<int>); cout << endl;

    // 먼저 정렬 범위 알고리즘을 사용하기 전에 정렬 필요
    sort(v.begin(), v.end(), Pred); // 12, 55가 10, 53보다 앞에 놓임.(정렬 기준이 Pred이므로)

    cout << "[v: 정렬] : ";
    for_each(v.begin(), v.end(), Print<int>); cout << endl;

    if(binary_search(v.begin(), v.end(), 32, Pred))
        cout << "32 원소가 존재합니다." << endl;
    else    
        cout << "32 원소가 존재하지 않습니다." << endl;

    if(binary_search(v.begin(), v.end(), 35, Pred))
        cout << "35 원소가 존재합니다." << endl;
    else    
        cout << "35 원소가 존재하지 않습니다." << endl;

    return 0;
}