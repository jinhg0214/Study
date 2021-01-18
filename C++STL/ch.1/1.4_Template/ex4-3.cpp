#include <iostream>

using namespace std;

template<typename T>
void Print(T a, T b){
    cout << a << ", "<< b << endl; 
}

// �ΰ��� �Ű������� ������ �Լ� ���ø�
template<typename T1, typename T2>
void Print2(T1 a, T2 b){
    cout << a << ", "<< b << endl; 
}

int main(){
    Print(10, 20);          // ���� ���
    Print(0.123, 1.123);    // �Ǽ� ���
    Print("ABC", "abcde");  // ���ڿ� ���

    // ��������� �Լ��� ���ø��� �����Ͽ� ȣ��
    Print<int>(10, 20);          // ���� ���
    Print<double>(0.123, 1.123);    // �Ǽ� ���
    Print<const char *>("ABC", "abcde");  // ���ڿ� ���

    Print2(10, 1.5);
    Print2("Hello", 100);

    return 0;
}