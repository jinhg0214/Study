#include <iostream>
#include <string>

using namespace std;


int main(){
    string s("Hello!");
    const char* sz;
    const char* buf;

    sz = s.c_str();
    buf = s.data();

    cout << "'\\0' ���ڷ� ������ ���ڿ�(C-Style): " << sz << endl;
    cout << "'\\0' ���� �������� �ʴ� ���� �迭: ";
    for(int i =0; i<6; i++){
        cout << buf[i];
    } 
    cout << endl;

    return 0;
}