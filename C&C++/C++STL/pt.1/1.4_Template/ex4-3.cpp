#include <iostream>

using namespace std;

template<typename T>
void Print(T a, T b){
    cout << a << ", "<< b << endl; 
}

// 두개의 매개변수를 가지는 함수 템플릿
template<typename T1, typename T2>
void Print2(T1 a, T2 b){
    cout << a << ", "<< b << endl; 
}

int main(){
    Print(10, 20);          // 정수 출력
    Print(0.123, 1.123);    // 실수 출력
    Print("ABC", "abcde");  // 문자열 출력

    // 명시적으로 함수의 템플릿을 지정하여 호출
    Print<int>(10, 20);          // 정수 출력
    Print<double>(0.123, 1.123);    // 실수 출력
    Print<const char *>("ABC", "abcde");  // 문자열 출력

    Print2(10, 1.5);
    Print2("Hello", 100);

    return 0;
}