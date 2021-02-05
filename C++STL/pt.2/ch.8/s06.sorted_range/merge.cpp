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
    cout << "========== 1. merge(b,e,b2,e2,t) ==========" << endl;
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

    // [t,p)
    vector<int> v3(10);

    cout << "v1 : ";
    for_each(v1.begin(), v1.end(), Print<int>); cout << endl;
    
    cout << "v2 : ";
    for_each(v2.begin(), v2.end(), Print<int>); cout << endl;
    
    vector<int>::iterator iter_end;
    iter_end = merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

    cout << "v3 : ";
    for_each(v3.begin(), v3.end(), Print<int>); cout << endl;

    return 0;
}