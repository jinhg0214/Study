#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template<typename T>
struct Plus{
    T operator()(const T& left, const T& right) const{
        return left + right;
    }
};

int main(){
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    
    vector<int> v2;
    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(3);

    vector<int> v3;

    // STL ������ plus<int>���
    // transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), plus<int>());
    // ����� ���� ������ Plus<int>���
    transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), Plus<int>()); 
    // �� Plus<int>()?? T operator()(const T& left, const T& right)�̸� ���ڰ� �ʿ����� ����?

    cout << "v3 : ";
    for(vector<int>::size_type i = 0; i< v3.size(); i++)
        cout << v3[i] << " ";
    cout << endl;

    return 0;
}