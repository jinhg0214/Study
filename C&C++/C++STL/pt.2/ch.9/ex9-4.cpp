#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;

template<typename T>
struct Plus{
    typedef T first_argument_type;
    typedef T second_argument_type;
    typedef T result_type;

    T operator()(const T& left, const T& right) const{
        return left + right;
    }
};

int main(){
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    vector<int> v3(3);

    // 사용자 정의 조건자 Plus<int> 사용
    transform(v1.begin(),v1.end(), v3.begin(), binder1st<Plus<int>>(Plus<int>(), 100));

    cout << "v3 : ";
    for(vector<int>::iterator iter = v3.begin(); iter != v3.end(); iter++ ){
        cout << *iter << " ";
    } cout << endl;

    return 0;

}