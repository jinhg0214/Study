// adjacent_find() : 현재 원소가 다음 원소와 같아지는 첫 원소의 반복자를 반환
// *adjacent : 인접한, 가까운 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 이항 연산자
// 두 항 사이에 차이가 10 초과라면 참을 반환
bool Pred(int a, int b){
    return abs(b-a) > 10;
}

int main(){
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(30);
    v.push_back(40);
    v.push_back(40);
    v.push_back(50);

    for(vector<int>::size_type i=0; i<v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    vector<int>::iterator iter;
    // 구간 [v.begin(), v.end())에서 현재 원소와 다음 원소가 같아지는 첫 원소 반복자를 반환
    iter = adjacent_find(v.begin(), v.end());

    if(iter != v.end()){
        cout << *iter << endl;
    }

    for(; iter != v.end(); iter++)
        cout << *iter << " ";
    cout << endl << "==================================" << endl;

    //////////// 현재 원소와 다음 원소가 같은 원소가 없다면 찾는 구간의 끝 반복자를 반환! //////////
    v.clear();

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    for(vector<int>::size_type i=0; i<v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    vector<int>::iterator iter_b = v.begin();
    vector<int>::iterator iter_e = v.begin()+2; 

    // 구간 [iter_b, iter_e) 의 순차열 : 10, 20 이므로
    // 찾는 원소가 없으므로, 리턴값은 iter의 구간 끝인 iter_e가 반환됨(30)
    iter = adjacent_find(iter_b, iter_e);

    if(iter != iter_e) // 맞는 표현(iter와 iter_e를 비교)
        cout << *iter << endl;

    cout << "==================================" << endl;
    if(iter != v.end()) // 틀린 표현(iter와 범위 밖 v.end()를 비교)
        cout << *iter << endl; // 잘못된 결과값이 리턴됨

    iter_b = v.begin();
    iter_e = v.end();
    iter = adjacent_find(iter_b, iter_e);

    // 이 경우엔 범위가 벡터 전체이므로 iter_e나, v.end()로 비교해도 같은 결과값 출력
    if(iter != v.end())
        cout << *iter << endl; // 결과값이 없으므로, 구간의 끝인 v.end()가 반환됨

    if(iter != v.end()) 
        cout << *iter << endl; // 마찬가지


    /////////////////////////////////////////////////////////////////////////////////
    // 순차열에서 인접한 원소가 특정 조건에 따라 인접한지 찾고싶은 경우
    // adjacent_find(b,e,f) : f는 이항 조건자 

    v.clear();

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(50);
    v.push_back(90);

    iter = adjacent_find(v.begin(), v.end(), Pred); // Pred(*p, *(p+1))가 참인 첫 원소의 반복자를 리턴 
    if(iter != v.end())
        cout << *iter << endl; // 30

    for(; iter != v.end(); iter++) // 30부터 순차열을 출력
        cout << *iter << " ";
    cout << endl;

    return 0;

}