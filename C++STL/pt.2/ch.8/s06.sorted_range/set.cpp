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
    cout << "========== 1. set_union(b,e,b2,e2,t) ==========" << endl;
    // [b,e)
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    // [b2,e2)
    vector<int> v2;
    v2.push_back(20);
    v2.push_back(30);
    v2.push_back(60);

    vector<int> v3(10);
    vector<int>::iterator iter_end;

    iter_end = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

    cout << "v1 : ";
    for_each(v1.begin(), v1.end(), Print<int>); cout << endl; 

    cout << "v2 : ";
    for_each(v2.begin(), v2.end(), Print<int>); cout << endl;

    cout << "v3 합집합 : ";
    for(vector<int>::iterator iter = v3.begin(); iter != iter_end; iter++)
        cout << *iter << " ";
    cout << endl;

    cout << "========== 2. set_intersection(b,e,b2,e2,t) ==========" << endl;
    vector<int> v4(5);
    iter_end = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v4.begin());
    
    cout << "v4 교집합 : ";
    for(vector<int>::iterator iter = v4.begin(); iter != iter_end; iter++)
        cout << *iter << " ";
    cout << endl;

    cout << "========== 3. set_difference(b,e,b2,e2,t) ==========" << endl;
    vector<int> v5(10);
    iter_end = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v5.begin());
    
    cout << "v5 차집합 : ";
    for(vector<int>::iterator iter = v5.begin(); iter != iter_end; iter++)
        cout << *iter << " ";
    cout << endl;

    cout << "========== 4. set_symmetric_difference(b,e,b2,e2,t) ==========" << endl;
    vector<int> v6(10);
    iter_end = set_symmetric_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v6.begin());
    
    cout << "v6 대칭 차집합 : ";
    for(vector<int>::iterator iter = v6.begin(); iter != iter_end; iter++)
        cout << *iter << " ";
    cout << endl;



    return 0;
}