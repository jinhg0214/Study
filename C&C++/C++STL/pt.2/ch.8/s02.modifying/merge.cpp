#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template<typename T>
void Print(T n){
    cout << n << " ";
}

template<typename T>
struct Greater{
    bool operator()(const T& left, const T& right) const{
        return left > right;
    }
};

int main(){
    cout << "==========1.merge()==========" << endl;
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(30);
    v1.push_back(50);
    v1.push_back(60);
    v1.push_back(80);

    vector<int> v2;
    v2.push_back(20);
    v2.push_back(40);
    v2.push_back(70);

    vector<int> v3(10);

    vector<int>::iterator iter_end;

    iter_end = merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin()); // 목적지 끝 반복자를 반환함.

    cout << "v1 : ";
    for_each(v1.begin(), v1.end(), Print<int>); cout << endl;

    cout << "v2 : ";
    for_each(v2.begin(), v2.end(), Print<int>); cout << endl;

    cout << "v3 : ";
    for_each(v3.begin(), v3.end(), Print<int>); cout << endl;
    cout << "v3(합병 순차열): " << *v3.begin() << '~' << *(iter_end-1) << endl;

    //////////////////////////////////////////////////
    // greater 정렬기준 사용
    cout << "==========2.merge()(greater)==========" << endl;
   
    vector<int> v4(10);

    vector<int>::iterator iter_end2;
    iter_end2 = merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v4.begin(), Greater<int>()); // 동작 안함??

    cout << "v1 : ";
    for_each(v1.begin(), v1.end(), Print<int>); cout << endl;

    cout << "v2 : ";
    for_each(v2.begin(), v2.end(), Print<int>); cout << endl;

    cout << "v4 : ";
    for_each(v4.begin(), v4.end(), Print<int>); cout << endl;

    return 0;
}