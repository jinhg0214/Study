// 사전식 순서 비교

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
struct Less{
    bool operator() (const T& left, const T& right) const{
        return left < right;
    }
};

int main(){

    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    vector<int> v2;
    v2.push_back(10);
    v2.push_back(20);
    v2.push_back(50);

    vector<int> v3;
    v3.push_back(10);
    v3.push_back(20);
    v3.push_back(30);

    // [v1.begin(),v1.end())가, [v2.begin(), v2.end())보다 사전순서가 less인가? 
    if(lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end())){
        cout << "v1 < v2" << endl; // 10, 20은 같지만 30 < 50 이므로, true를 반환함.
    } else {
        cout << "v1 >= v2" << endl;
    }


    if(lexicographical_compare(v1.begin(), v1.end(), v3.begin(), v3.end())){
        cout << "v1 < v3" << endl;
    } else {
        cout << "v1 >= v3" << endl; // 두 순차열이 같으므로 false 를 반환함
    }

    //////////////////////////////////////////////////////////////////////////////////
    // lexicographical_compare() 조건 연산자
    v2.clear();
    v2.push_back(10);
    v2.push_back(25);
    v2.push_back(30);

    if(lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end(), less<int>() ) ){
        cout << " 기준 less, v1과 v2의 비교 : true" << endl;
    } else {
        cout << " 기준 less, v1과 v2의 비교 : flase" << endl;
    }

    if(lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end(), greater<int>() ) ){
        cout << " 기준 greater, v1과 v2의 비교 : true" << endl;
    } else {
        cout << " 기준 greater, v1과 v2의 비교 : flase" << endl;
    }

    if(lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end(), Less<int>() ) ){
        cout << " 사용자 기준 Less, v1과 v2의 비교 : true" << endl;
    } else {
        cout << " 사용자 기준 Less, v1과 v2의 비교 : flase" << endl;
    }


}