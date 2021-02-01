#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Pred(int n){
    return 25 < n;
}

int main(){
    //////////////////////////////////////////////////////////////////////////
    // 1. count(b,e,t)
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(30);
    v.push_back(50);

    for(vector<int>::size_type i=0; i<v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    // 구간 [v.begin(), v.end()) 에서 30의 원소의 개수를 반환;
    int n = count(v.begin(), v.end(), 30);

    cout << "30의 개수 : " << n << endl;
    cout << "==============================" << endl;

    //////////////////////////////////////////////////////////////////////////
    // count_if(b,e,f) : f는 단항 조건자. 원소를 가리키는 반복자 p 에 대해 f(*p)가 참인 원소의 개수를 반환
    v.clear();
    
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    for(vector<int>::size_type i=0; i<v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    // 구간 [v.begin(), v.end()) 에서 25보다 큰 원소의 개수를 반환
    n = count_if(v.begin(), v.end(), Pred);
    
    cout << "25보다 큰 원소의 개수 : "<< n << endl;



    return 0;
}