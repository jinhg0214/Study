#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Integer{
    int data;
public:
    explicit Integer(int d = 0):data(d) {}
    int operator()(){ // 정수를 1씩 증가시키는 멤버 함수
        return data++;
    }
};

template<typename T>
void Print(T n){
    cout << n << " ";
}

int main(){
    //////////////////////////////////////////////////
    cout << "==========1.generate()==========" << endl;
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    cout << "v : ";
    for_each(v.begin(),v.end(), Print<int>); 
    cout << endl;

    // [v.begin(), v.end())의 원소를 1~5로 채움
    generate(v.begin(), v.end(), Integer(1));

    cout << "v : ";
    for_each(v.begin(),v.end(), Print<int>); 
    cout << endl;

    // [v.begin(), v.end())의 원소를 100~104로 채움
    generate(v.begin(), v.end(), Integer(100));

    cout << "v : ";
    for_each(v.begin(),v.end(), Print<int>); 
    cout << endl;

    // [v.begin(), v.begin()+3 )의 원소를 1~3로 채움
    generate(v.begin(), v.begin()+3, Integer(1));

    cout << "v : ";
    for_each(v.begin(),v.end(), Print<int>); 
    cout << endl;


    return 0;
}