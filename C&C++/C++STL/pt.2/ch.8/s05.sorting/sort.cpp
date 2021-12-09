#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
void Print(T n){
    cout << n << " ";
}

bool Greater(int left, int right){
    return left > right;
}

int main(){
    //////////////////////////////////////////////////
    cout << "========== 1. sort(b,e) ==========" << endl;
    vector<int> v1;

    for(int i =0; i<100; i++)
        v1.push_back( rand()%1000 );

    cout << "v1[정렬 전] : ";
    for_each(v1.begin(),v1.end(),Print<int>); cout << endl;

    sort(v1.begin(),v1.end());
    cout << "v1[정렬 less] : ";
    for_each(v1.begin(),v1.end(),Print<int>); cout << endl;

    sort(v1.begin(), v1.end(), Greater);
    cout << "v1[정렬 greater] : ";
    for_each(v1.begin(),v1.end(),Print<int>); cout << endl;

    //////////////////////////////////////////////////
    cout << "========== 2. stable_sort(b,e) ==========" << endl;

    vector<int> v2;
    v2.push_back(30);
    v2.push_back(50);
    v2.push_back(30);
    v2.push_back(20);
    v2.push_back(40);
    v2.push_back(10);
    v2.push_back(40);

    cout << "v2[정렬 전] : ";
    for_each(v2.begin(),v2.end(),Print<int>); cout << endl;

    stable_sort(v2.begin(),v2.end());
    cout << "v2[정렬 less] : ";
    for_each(v2.begin(),v2.end(),Print<int>); cout << endl;

    stable_sort(v2.begin(), v2.end(), Greater);
    cout << "v2[정렬 greater] : ";
    for_each(v2.begin(),v2.end(),Print<int>); cout << endl;

    //////////////////////////////////////////////////
    cout << "========== 3. partial_sort(b,e) ==========" << endl;

    vector<int> v3;

    for(int i =0; i<100; i++)
        v3.push_back( rand()%1000 );

    partial_sort(v3.begin(),v3.begin()+20, v3.end()); // 상위 20개만 정렬

    cout << "v3[상위 정렬 20개] : ";
    for_each(v3.begin(),v3.begin()+20,Print<int>); cout << endl;

    cout << "v3[하위 80개] : ";
    for_each(v3.begin()+20,v3.end(),Print<int>); cout << endl;

    vector<int> v4(25);
    // v3를 상위 25개만 정렬 후 v4로 복사
    partial_sort_copy(v3.begin(), v3.begin()+20, v4.begin(), v4.end());

    cout << "v4[복사 후] : ";
    for_each(v4.begin(), v4.end(),Print<int>); cout << endl;

    return 0;

}