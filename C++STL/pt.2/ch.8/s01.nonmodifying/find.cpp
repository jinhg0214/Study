#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Pred(int n){
    return n > 35;
}

bool Pred2(int left, int right){
    return left <= right;
}

bool Pred3(int left, int right){
    return left > right;
}

int main(){
    //////////////////////////////////////////////////////////////////////////
    // find() : 특정 원소를 찾는 알고리즘
    
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    for(vector<int>::size_type i=0; i<v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    vector<int>::iterator iter;
    iter = find(v.begin(),v.end(), 20); // [v.begin(), v.end()) 에서 원소 20을 찾음

    if(iter != v.end()){
        cout << *iter << "가 존재합니다." << endl;
    } cout << "==============================" << endl;
    
    //////////////////////////////////////////////////////////////////////////
    // find_if() : 특정 조건에 맞는 원소를 찾는 알고리즘

    // 구간 [v.begin(), v.end()) 에서 35보다 큰 원소를 찾아 첫번쨰 원소를 반환 
    iter = find_if(v.begin(), v.end(), Pred);
    if(iter != v.end()){
        cout << "순차열에서 35보다 큰 첫번째 원소: " << *iter << endl;
    } cout << "==============================" << endl;

    //////////////////////////////////////////////////////////////////////////
    // find_end() : 
    
    v.clear();

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.push_back(60);
    v.push_back(70);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    
    vector<int> v2;
    
    v2.push_back(30);
    v2.push_back(40);
    v2.push_back(50);

    // [v.begin(), v.end())의 순차열 구간에, [v2.begin(), v2.end())의 순차열이 일치하는지 판단하여,
    // 일치하는 순차열 구간이 여러개라면, 
    // 마지막 순차열의 첫 원소 반복자를 반환
    iter = find_end(v.begin(), v.end(), v2.begin(), v2.end());
    if(iter != v.end()){
        // 일치하는 마지막 순차열의 첫 원소 반복자 iter
        cout << "iter : "<< *iter << endl; // 30,40,50이 두 순차열 구간이 존재하므로, 마지막 순차열이 반환됨
        cout << "iter-1 : "<< *(iter-1) << endl;
        cout << "iter+1 : "<< *(iter+1) << endl;
    } cout << "==============================" << endl;

    // find_end() 조건자 버전
    v.clear(); v2.clear();
    v.push_back(10);
    v.push_back(15);
    v.push_back(20);
    v.push_back(40);
    v.push_back(50);
    v.push_back(60);
    v.push_back(10);
    v.push_back(11);
    v.push_back(12);
    v.push_back(80);

    v2.push_back(10);
    v2.push_back(15);
    v2.push_back(20);

    iter = find_end(v.begin(), v.end(), v2.begin(), v2.end(), Pred2); // Pred2조건에 맞는 구간 검색
    if(iter != v.end()){
        cout << "iter : "<< *iter << endl; 
        cout << "iter-1 : "<< *(iter-1) << endl;
        cout << "iter+1 : "<< *(iter+1) << endl;
    } cout << "==============================" << endl;

    //////////////////////////////////////////////////////////////////////////
    // find_first_of() : 두 순차열을 비교하여, 모든 원소 중 같은 원소가 하나라도 발견되면 첫 원소의 반복자를 반환
    v.clear(); v2.clear();
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    v2.push_back(40);
    v2.push_back(80);
    v2.push_back(20);

   
    iter = find_first_of(v.begin(), v.end(), v2.begin(), v2.end());

    if(iter != v.end()){
        // v1에서 v2의 원소가 첫번째로 발견되는 위치는 20이므로 20이 리턴됨
        cout << "iter : " << *iter << endl; 
    } cout << "==============================" << endl;

    // find_first_of() 조건자 연산
    iter = find_first_of(v.begin(), v.end(), v2.begin(), v2.end(), Pred3);

    // v에서 v2보다 큰 원소는 30이 처음이므로, 30이 반환됨
    
    if(iter != v.end())
        cout << "iter : " << *iter << endl; 


    return 0;
}