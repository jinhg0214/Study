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
        strcpy(buf, sz); // sz�� �о� char* �� �����Ͽ� buf�� ������
    }

    operator const char* () const{ // Ÿ�� ��ȯ ������
        return buf;
    }
};

int main(){
    String s("Hello!");
    const char* sz = s;

    cout << sz << endl;

    return 0;
}



