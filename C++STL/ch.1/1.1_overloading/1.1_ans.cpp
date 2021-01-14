/*
1. 

2. int operator()(int, int, int);

3. int operator[](int);

4. 
*/
#include <iostream>
#include <cstring>

using namespace std;

class String{
    char buf[100];
public:
    String(const char* sz){
        strcpy(buf, sz); // sz를 읽어 char* 를 복사하여 buf로 가져옴
    }

    operator const char* () const{ // 타입 변환 연산자
        return buf;
    }
};

int main(){
    String s("Hello!");
    const char* sz = s;

    cout << sz << endl;

    return 0;
}



