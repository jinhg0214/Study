// 클래스 템플릿 예제
#include <iostream>
#include <string>

using namespace std;

template<typename T>
class Array{
    T *buf;
    int size;
    int capacity;
public:
    explicit Array(int cap = 100):buf(0), size(0), capacity(cap){ // 명시적 생성자
        buf = new T[capacity];
    }

    ~Array(){
        delete [] buf;
    }

    void Add(T data){
        buf[size++] = data;
    }

    T operator[](int idx) const{
        return buf[idx];
    }

    int GetSize() const{
        return size;
    }
};

int main(){

    Array<int> iarr;
    iarr.Add(10);
    iarr.Add(20);
    iarr.Add(30);

    for(int i =0; i<iarr.GetSize() ; ++i){
        cout << iarr[i] << endl;
    }
    cout << endl;

    Array<double> darr;
    darr.Add(10.12);
    darr.Add(20.12);
    darr.Add(30.12);

    for(int i =0; i<darr.GetSize() ; ++i){
        cout << darr[i] << endl;
    }
    cout << endl;

    Array<string> sarr;
    sarr.Add("abc");
    sarr.Add("ABC");
    sarr.Add("Hello!");

    for(int i =0; i<sarr.GetSize() ; ++i){
        cout << sarr[i] << endl;
    }
    cout << endl;




}