#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template<typename T>
void Print(T n){
    cout << n << " ";
}

// 사용자 함수의 매개변수는 출력 매개변수로 사용되어야 하므로 꼭 &를 사용함!!(값을 수정해야 하므로)
void Func(int& r){
    r += 5;
}

// 값을 누적하는 클래스
class Accumulation{
    int total;
public:
    explicit Accumulation(int init=0):total(init){}
    void operator()(int& r){
        total += r;
        r = total;
    }
};

int main(){
    cout << "==========1.fill()==========" << endl;
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    cout << "fill 이전 v : ";
    for_each(v.begin(), v.end(), Print<int>); cout << endl;

    // 구간 [v.begin(), v.end())의 모든 원소를 0으로 채움
    fill(v.begin(), v.end(), 0);

    cout << "fill 이후 v : ";
    for_each(v.begin(), v.end(), Print<int>); cout << endl;

    ///////////////////////////////////////////////////////////////////////////////
    // 2. fill_n()
    cout << "==========2.fill_n()==========" << endl;
    // 구간 [v.begin(), v.begin()+3)의 모든 원소를 55로 채움
    fill_n(v.begin(), 3, 55);
    for_each(v.begin(), v.end(), Print<int>); cout << endl;

    ///////////////////////////////////////////////////////////////////////////////
    // 3. for_each() - 함수
    cout << "==========3.for_each()==========" << endl;
    v.clear();
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    for_each(v.begin(), v.end(), Func); // [v.begin(), v.end())의 모든 원소에 Func(*p)를 적용함.
    
    cout << "v : ";
    for_each(v.begin(), v.end(), Print<int>); cout << endl;

    ///////////////////////////////////////////////////////////////////////////////
    // 4. for_each() - 함수자
    cout << "==========4.for_each()==========" << endl;
    
    v.resize(5);
    v.clear();

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    cout << "v : ";
    for_each(v.begin(), v.end(), Print<int>); cout << endl;

    // [v.begin(), v.end()) 모든 원소를 초기값 0부터 시작해 *p += *(p-1)를 적용함
    for_each(v.begin(), v.end(), Accumulation(0)); 

    cout << "v : ";
    for_each(v.begin(), v.end(), Print<int>); cout << endl; // v의 값이 변경됨!!

    return 0;
}