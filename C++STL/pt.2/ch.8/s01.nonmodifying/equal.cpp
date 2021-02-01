#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 두 원소의 차이가 5 미만이면 참을 반환
bool Pred(int left, int right){
    return abs(right-left) < 5;
}

int main(){
    //////////////////////////////////////////////////////////////////////////
    // equal(b,e,b2) : [b,e)의 순차열과, 구간 [b2,b2+(e-b))의 순차열이 같은지 판단하는 알고리즘
    vector<int> v1, v2;

    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    v2.push_back(10);
    v2.push_back(20);
    v2.push_back(30);
    v2.push_back(40);
    v2.push_back(50);

    cout << "v1 : ";
    for(vector<int>::size_type i=0; i<v1.size(); i++)
        cout << v1[i] << " ";
    cout << endl;

    cout << "v2 : ";
    for(vector<int>::size_type i=0; i<v2.size(); i++)
        cout << v2[i] << " ";
    cout << endl;   

    // 구간 [v1.begin(), v1.end())와 구간 [v2.begin(), v2.begin()+3)을 비교
    if(equal(v1.begin(), v1.end(), v2.begin()))
        cout << "두 순차열은 같습니다" << endl;
    cout << "==============================" << endl;

    //////////////////////////////////////////////////////////////////////////
    // equal(b,e,b2,f) : 이항 조건자로 각 순차열의 반복자 p,q에 대해 f(*p, *q)가 모두 참이면 equal()은 참을 반환

    v1.clear(); v2.clear();

    v1.push_back(10);
    v1.push_back(21);
    v1.push_back(30);

    v2.push_back(10);
    v2.push_back(20);
    v2.push_back(33);

     cout << "v1 : ";
    for(vector<int>::size_type i=0; i<v1.size(); i++)
        cout << v1[i] << " ";
    cout << endl;

    cout << "v2 : ";
    for(vector<int>::size_type i=0; i<v2.size(); i++)
        cout << v2[i] << " ";
    cout << endl;   

    if(equal(v1.begin(), v1.end(), v2.begin(), Pred)){
        cout << "두 순차열의 차이는 5미만입니다." << endl;
    }

    return 0;
}
